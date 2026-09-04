#!/usr/bin/env python3
"""cb bridge broker — single-process cross-connect for two interactive programs.

A = interactor (questioner), B = solution (responder): A's stdout feeds B's
stdin and vice versa; both programs' stderr is relayed as [name:err] lines.
The broker is the ONLY writer of the console and interaction.log, so tagged
lines appear in true exchange order — the previous tee+sed side-pipelines ran
as independent processes and could print [A]/[B] lines out of order (and left
an untagged, unordered log).

Usage: cb_bridge.py <A> <B> <log>        Deps: python3 stdlib only.
"""
import os
import selectors
import signal
import subprocess
import sys
import time

CHUNK = 65536
GRACE = 0.5      # seconds between SIGTERM and SIGKILL when stopping
PAUSE_AT = 1 << 20    # stop reading a source once its destination holds this much
RESUME_AT = 1 << 18   # resume reading once the destination drains below this
ECHO_CAP = 1 << 20    # flush a newline-free partial line once it grows past this


class SpawnError(Exception):
    pass


class Prog:
    def __init__(self, path):
        self.name = os.path.basename(path).encode()
        # start_new_session: own process group, so a terminal Ctrl+C reaches the
        # broker only; the broker TERMs the groups itself on the way down.
        try:
            self.proc = subprocess.Popen(
                [path], stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                stderr=subprocess.PIPE, start_new_session=True)
        except OSError as e:
            sys.stderr.write("cb bridge: cannot run %s: %s\n" % (path, e))
            raise SpawnError(path)
        self.in_fd = self.proc.stdin.fileno()    # raw fd for os.write
        self.out_fd = self.proc.stdout.fileno()
        self.err_fd = self.proc.stderr.fileno()
        for fd in (self.in_fd, self.out_fd, self.err_fd):
            os.set_blocking(fd, False)
        self.outbuf = bytearray()   # pending bytes toward this program's stdin
        self.feed_eof = False       # its feeder's stdout saw EOF
        self.dead = False           # write side errored (EPIPE): stop feeding
        self.in_closed = False      # we closed its stdin (EOF delivered)
        self.wkey = None            # write registration key, or None


def kill_prog(p):
    """TERM -> grace -> KILL one child, then reap it (orphan-proof)."""
    try:
        os.killpg(p.proc.pid, signal.SIGTERM)
    except (ProcessLookupError, PermissionError):
        pass
    try:
        p.proc.wait(timeout=GRACE)
    except subprocess.TimeoutExpired:
        try:
            os.killpg(p.proc.pid, signal.SIGKILL)
        except ProcessLookupError:
            pass
        try:
            p.proc.wait(timeout=5)
        except subprocess.TimeoutExpired:
            pass


class Broker:
    def __init__(self, a, b, logf):
        self.a, self.b = a, b
        self.sel = selectors.DefaultSelector()
        self.t0 = time.monotonic()
        self.log = logf
        self.srcs = {}              # src fd -> (tag bytes, dst Prog or None)
        self.echos = {}             # src fd -> partial-line buffer for tagging
        self.feeder = {}            # dst Prog -> src fd that feeds it
        self.paused = set()         # src fds paused for backpressure

    # ---- console / log output (single writer => ordered by construction) ----
    def emit(self, tag, line):
        ms = (time.monotonic() - self.t0) * 1000.0
        tagged = b"[" + tag + b"] " + line + b"\n"
        for sink, prefix in ((sys.stderr.buffer, b""),
                             (self.log, ("%9.2fms " % ms).encode())):
            try:
                sink.write(prefix + tagged)
                sink.flush()
            except OSError:
                pass

    def echo_chunk(self, src, chunk):
        buf = self.echos[src]
        buf += chunk
        while buf:
            i = buf.find(b"\n")
            if i < 0:
                if len(buf) > ECHO_CAP:   # newline-free monster: flush the
                    self.emit(self.srcs[src][0], bytes(buf))  # partial as its
                    buf.clear()           # own line instead of buffering it all
                break
            self.emit(self.srcs[src][0], bytes(buf[:i]))
            del buf[:i + 1]

    # ---- feeding a program's stdin (non-blocking, backpressure-safe) --------
    def feed(self, prog, data):
        if not prog.dead and not prog.in_closed:
            prog.outbuf += data
            self.pump(prog)

    def pump(self, prog):
        while prog.outbuf and not prog.dead:
            try:
                n = os.write(prog.in_fd, prog.outbuf)
            except BlockingIOError:
                break
            except OSError:                 # EPIPE: the program is gone
                prog.dead = True
                prog.outbuf.clear()
                break
            del prog.outbuf[:n]
        self.set_write_reg(prog, bool(prog.outbuf) and not prog.dead)
        if len(prog.outbuf) < RESUME_AT:
            self.resume_feeds(prog)
        self.maybe_close_in(prog)

    def set_write_reg(self, prog, want):
        if want and prog.wkey is None and not prog.in_closed and not prog.dead:
            prog.wkey = self.sel.register(prog.in_fd, selectors.EVENT_WRITE)
        elif not want and prog.wkey is not None:
            self.sel.unregister(prog.in_fd)
            prog.wkey = None

    def pause_src(self, src):
        # the destination is backing up: stop reading so the kernel pipe
        # throttles the producer instead of the broker ballooning in RAM
        if src in self.srcs:
            self.sel.unregister(src)
            self.paused.add(src)

    def resume_feeds(self, prog):
        src = self.feeder.get(prog)
        if src is not None and src in self.paused:
            if src in self.srcs:
                self.sel.register(src, selectors.EVENT_READ)
            self.paused.discard(src)

    def maybe_close_in(self, prog):
        # deliver EOF once nothing more can ever be written toward the program
        if prog.in_closed or prog.outbuf:
            return
        if prog.feed_eof or prog.dead:
            self.set_write_reg(prog, False)
            try:
                prog.proc.stdin.close()
            except OSError:
                pass
            prog.in_closed = True

    # ---- event loop ---------------------------------------------------------
    def add_src(self, src, tag, dst=None):
        self.sel.register(src, selectors.EVENT_READ)
        self.srcs[src] = (tag, dst)
        self.echos[src] = bytearray()
        if dst is not None:
            self.feeder[dst] = src

    def run(self):
        self.add_src(self.a.out_fd, self.a.name, self.b)
        self.add_src(self.b.out_fd, self.b.name, self.a)
        self.add_src(self.a.err_fd, self.a.name + b":err")
        self.add_src(self.b.err_fd, self.b.name + b":err")
        while self.sel.get_map():
            for key, mask in self.sel.select():
                fd = key.fd
                if mask & selectors.EVENT_WRITE:
                    self.pump(self.prog_by_in_fd(fd))
                    continue
                try:
                    chunk = os.read(fd, CHUNK)
                except BlockingIOError:
                    continue
                except OSError:
                    chunk = b""
                if chunk:
                    tag, dst = self.srcs[fd]
                    if dst is not None:
                        self.feed(dst, chunk)
                        if len(dst.outbuf) > PAUSE_AT:
                            self.pause_src(fd)
                    self.echo_chunk(fd, chunk)
                else:                           # EOF
                    self.sel.unregister(fd)
                    tag, dst = self.srcs.pop(fd)
                    buf = self.echos.pop(fd, None)
                    if buf:
                        self.emit(tag, bytes(buf))
                    if dst is not None:
                        dst.feed_eof = True
                        self.maybe_close_in(dst)

    def prog_by_in_fd(self, fd):
        return self.a if fd == self.a.in_fd else self.b

    def teardown(self):
        # a second Ctrl+C while the TERM grace runs must not abort the KILL
        # escalation — ignore further stop signals until the children are reaped
        for sig in (signal.SIGINT, signal.SIGTERM):
            try:
                signal.signal(sig, signal.SIG_IGN)
            except ValueError:
                pass
        for p in (self.a, self.b):
            if p is not None:
                kill_prog(p)
        try:
            self.log.close()
        except OSError:
            pass


def main():
    if len(sys.argv) != 4:
        sys.stderr.write("usage: cb_bridge.py <interactor> <solution> <log>\n")
        return 2
    a_path, b_path, logpath = sys.argv[1:4]
    print("cb bridge: A = %s (interactor), B = %s (solution); log: %s"
          % (os.path.basename(a_path), os.path.basename(b_path), logpath),
          file=sys.stderr)
    print("cb bridge: Ctrl+C stops both sides", file=sys.stderr)

    def on_term(signum, frame):
        raise KeyboardInterrupt          # same path as Ctrl+C below

    signal.signal(signal.SIGTERM, on_term)   # before any child exists: no window

    try:
        logf = open(logpath, "wb")
    except OSError as e:
        sys.stderr.write("cb bridge: cannot open log %s: %s\n" % (logpath, e))
        return 1

    a = b = None
    try:
        try:
            a = Prog(a_path)
            b = Prog(b_path)
        except SpawnError:                # a half-started pair must not leak
            if a is not None and b is None:
                kill_prog(a)
            logf.close()
            return 126
        br = Broker(a, b, logf)
        br.run()
        for p in (a, b):                  # both pipes drained; reap
            p.proc.wait()
        logf.close()
        rc = b.proc.returncode if b.proc.returncode is not None else 1
        if rc < 0:
            rc = 128 - rc
        return rc
    except KeyboardInterrupt:
        sys.stderr.write("cb bridge: stopped\n")
        Broker(a, b, logf).teardown()
        return 130


if __name__ == "__main__":
    sys.exit(main())

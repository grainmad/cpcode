# cb — short-name front for the cpcode CMake workflow. Optional convenience;
# pure `cmake --build -t <full.name>` keeps working without it.
#
# Usage:
#   source tools/cb.sh
#   cd cf/contest/2003
#   cb A / cb run-A / cb test-A     # build / run (stdin passthrough) / judge samples
#   cb A B C -j 8                   # several targets, flags pass through
#   cb stress gen brute A 1000 10   # build the trio, then stress: iters, tl
#
# Name resolution (per argument): exact full name in target-map.tsv ->
# cwd prefix (cf/contest/2003 + A -> cf.contest.2003.A) -> unique suffix
# match repo-wide; ambiguous bare names are rejected with candidates listed.
# Everything is located relative to `git rev-parse --show-toplevel`, so the
# script works in any clone and on any machine.

_cb_setup() {
  _cb_root=$(git rev-parse --show-toplevel 2>/dev/null) || { echo "cb: not inside a git repo" >&2; return 1; }
  _cb_build=""
  local b
  for b in "${CP_BUILD_DIR:-$_cb_root/build}" "$_cb_root/build-ninja"; do
    if [ -f "$b/target-map.tsv" ]; then _cb_build=$b; _cb_map=$b/target-map.tsv; return 0; fi
  done
  return 1
}

# _cb_cfg — (re)configure the tree cb uses: CP_BUILD_DIR, else build/,
# else build-ninja/ when only it exists; always at the REPO ROOT, never at
# the cwd (a bare `cmake -B build` inside cf/contest would fragment trees).
# Extra args pass through to cmake (-G Ninja, -DCMAKE_BUILD_TYPE=Debug, ...).
_cb_cfg() {
  local root b
  root=$(git rev-parse --show-toplevel 2>/dev/null) || { echo "cb: not inside a git repo" >&2; return 1; }
  if [ -n "${_cb_build:-}" ]; then b=$_cb_build
  elif [ -n "${CP_BUILD_DIR:-}" ]; then b=$CP_BUILD_DIR
  elif [ -d "$root/build-ninja" ] && [ ! -d "$root/build" ]; then b=$root/build-ninja
  else b=$root/build; fi
  echo "cb cfg: cmake -S $root -B $b" >&2
  cmake -S "$root" -B "$b" "$@"
}

# _cb_resolve — lookup with one reconfigure-and-retry: a miss usually means
# the cpp was just created and the make-tree map is stale (ninja trees
# reconfigure themselves, so this only costs anything there).
_cb_resolve() {
  if _cb_lookup "$1"; then return 0; fi
  echo "cb: '$1' not in target map; reconfiguring ..." >&2
  _cb_cfg >/dev/null 2>&1 || { echo "cb: reconfigure failed" >&2; return 1; }
  _cb_lookup "$1"
}

# _cb_lookup <name> <allow-dir?> -> prints "target<TAB>source" on stdout
_cb_lookup() {
  local x=$1 base verb="" hit rel prefix
  base=$x
  case $base in
    run-*) verb="run-"; base=${base#run-} ;;
    test-*) verb="test-"; base=${base#test-} ;;
  esac
  hit=$(awk -F'\t' -v n="$x" '$2==n{print $2"\t"$1; exit}' "$_cb_map")
  [ -n "$hit" ] && { printf '%s\n' "$hit"; return 0; }
  rel=${PWD#"$_cb_root"}; rel=${rel#/}; rel=${rel%/}
  [ -n "$rel" ] && prefix=${rel//\//.}
  # steps below resolve the exe name; re-attach the run-/test- verb on output
  if [ -n "${prefix:-}" ]; then
    hit=$(awk -F'\t' -v n="$prefix.$base" '$2==n{print $2"\t"$1; exit}' "$_cb_map")
    [ -n "$hit" ] && { printf '%s\t%s\n' "$verb${hit%%$'\t'*}" "${hit#*$'\t'}"; return 0; }
  fi
  hit=$(awk -F'\t' -v b="$base" 'BEGIN{gsub(/\./,"\\.",b); r="\\."b"$"} $2~r{print $2"\t"$1}' "$_cb_map")
  if [ "$(printf '%s' "$hit" | grep -c .)" -eq 1 ] && [ -n "$hit" ]; then
    printf '%s\t%s\n' "$verb${hit%%$'\t'*}" "${hit#*$'\t'}"; return 0
  fi
  if [ -z "$hit" ]; then
    echo "cb: '$x' not found (cwd prefix '${prefix:-<repo root>}', map: $_cb_map)" >&2
  else
    echo "cb: '$base' is ambiguous, candidates:" >&2
    printf '%s\n' "$hit" | while IFS=$'\t' read -r t s; do echo "  $t   <- $s" >&2; done | head -8
  fi
  return 1
}

# _cb_bin <source-path> -> binary path inside the build tree
_cb_bin() {
  local src=$1 d n
  d=$(dirname "$src"); n=$(basename "$src" .cpp)
  printf '%s/bin/%s/%s\n' "$_cb_build" "$d" "$n"
}

_cb_stress() {
  [ $# -ge 3 ] || { echo "usage: cb stress <gen> <brute> <sol> [iters=1000] [tl_sec=10]" >&2; return 1; }
  _cb_setup || return 1
  local g=$1 b=$2 s=$3; shift 3
  local rg rb rs
  rg=$(_cb_resolve "$g") || return 1
  rb=$(_cb_resolve "$b") || return 1
  rs=$(_cb_resolve "$s") || return 1
  cmake --build "$_cb_build" --target "${rg%%$'\t'*}" "${rb%%$'\t'*}" "${rs%%$'\t'*}" || return 1
  cmake -P "$_cb_root/cmake/stress.cmake" \
    "$(_cb_bin "${rg#*$'\t'}")" \
    "$(_cb_bin "${rb#*$'\t'}")" \
    "$(_cb_bin "${rs#*$'\t'}")" "$@"
}

_cb_help() {
  cat <<'EOF'
cb - short-name front for the cpcode CMake workflow

usage:
  cb <target>... [flags]          build targets (short names ok)
  cb <dir> | cb .                 build every cpp under a directory, recursively
  cb run-<target>                 run, stdin passthrough
  cb test-<target>                build + judge samples (AC/WA/TLE/RE)
  cb stress <gen> <brute> <sol> [iters] [tl]
                                  build the trio, then randomized duel
  cb new [--stress] <name>        scaffold <name>.cpp from template/sol.cpp
                                  (--stress adds gen.cpp + brute.cpp)
  cb cfg [cmake args...]          reconfigure the repo-root build tree
  cb help | -h | --help           this help

examples (inside cf/contest/2003):
  cb A                = cmake --build build -t cf.contest.2003.A
  cb run-A            run it, interactive stdin
  cb A D2 -j 8        several targets, flags pass through
  cb 2003             build the whole contest (directory aggregate)
  cb .                everything under the cwd, subdirs included
  cb new W --stress   scaffold W.cpp + gen.cpp + brute.cpp
  cb stress gen brute A 1000 10

name resolution (per argument):
  full target name -> cwd prefix (cf/contest + 2003.A) -> unique suffix
  repo-wide; ambiguous names list candidates

build tree: $CP_BUILD_DIR, else build/, else build-ninja/
prereq: git repo, cmake >= 3.20, C++ compiler, bash/zsh, sourced cb.sh
EOF
}

# _cb_subtree <dir-arg> -> prints every file target under that directory,
# recursively (directory aggregates only cover directly-contained cpps).
_cb_subtree() {
  local d=$1 abs sub list
  [ -z "$d" ] && d=.
  abs=$(cd "$d" 2>/dev/null && pwd) || { echo "cb: cannot enter '$d'" >&2; return 1; }
  if [ "$abs" = "$_cb_root" ]; then
    sub=""
  elif [ "${abs#"$_cb_root"/}" != "$abs" ]; then
    sub=${abs#"$_cb_root"/}
  else
    echo "cb: '$d' is outside the repo" >&2
    return 1
  fi
  if [ -z "$sub" ]; then
    echo all-problems                              # canonical full-repo target
  else
    list=$(awk -F'\t' -v p="$sub/" 'index($1,p)==1 && $3!="dir"{print $2}' "$_cb_map")
    if [ -z "$list" ]; then
      echo "cb: nothing under '$d' in map; reconfiguring ..." >&2
      _cb_cfg >/dev/null 2>&1 || { echo "cb: reconfigure failed" >&2; return 1; }
      list=$(awk -F'\t' -v p="$sub/" 'index($1,p)==1 && $3!="dir"{print $2}' "$_cb_map")
    fi
    if [ -z "$list" ]; then
      echo "cb: no targets under '$d'" >&2
      return 1
    fi
    printf '%s\n' "$list"
  fi
}

# _cb_new [--stress] <name> — scaffold <name>.cpp from the solution template
# (CP_TEMPLATE overrides template/sol.cpp); --stress additionally scaffolds
# gen.cpp / brute.cpp next to it. Never overwrites an existing file.
_cb_new() {
  local stress= name x
  for x in "$@"; do
    case $x in
      --stress|-s) stress=1 ;;
      -*) echo "cb new: unknown flag $x" >&2; return 1 ;;
      *) [ -n "$name" ] && { echo "cb new: one name only" >&2; return 1; }
         name=$x ;;
    esac
  done
  [ -n "$name" ] || { echo "usage: cb new [--stress] <name>   (e.g. cb new A, cb new 1228D)" >&2; return 1; }
  local root
  root=$(git rev-parse --show-toplevel 2>/dev/null) || { echo "cb: not inside a git repo" >&2; return 1; }
  local tpl="${CP_TEMPLATE:-$root/template/sol.cpp}"
  [ -f "$tpl" ] || { echo "cb: template not found: $tpl" >&2; return 1; }

  case $name in
    */*) mkdir -p "${name%/*}" ;;
  esac
  if [ -e "$name.cpp" ]; then
    echo "cb: '$name.cpp' already exists, not overwriting" >&2
    return 1
  fi
  cp "$tpl" "$name.cpp"
  echo "created: $name.cpp   (template: $tpl)"
  if [ "$stress" = 1 ]; then
    local sk
    for sk in gen:stress/gen.cpp brute:stress/brute.cpp; do
      local base=${sk%%:*} src=$root/template/${sk#*:}
      if [ -e "$base.cpp" ]; then
        echo "exists:  $base.cpp (kept)"
      elif [ -f "$src" ]; then
        cp "$src" "$base.cpp"
        echo "created: $base.cpp   (skeleton)"
      fi
    done
  fi
  echo "next: cb $name | cb run-$name | cb test-$name${stress:+ | cb stress gen brute $name}"
}

cb() {
  case "$1" in
    stress) shift; _cb_stress "$@"; return ;;
    cfg)    shift; _cb_cfg "$@"; return ;;
    new)    shift; _cb_new "$@"; return ;;
    -h|--help|help|"") _cb_help; return ;;
  esac
  _cb_setup || { _cb_cfg >/dev/null 2>&1 && _cb_setup; } || { echo "cb: no build tree, run: cb cfg" >&2; return 1; }
  local targets=() flags=() x t
  for x in "$@"; do
    case "$x" in
      -*) flags+=("$x"); continue ;;
    esac
    local y=${x%/}
    y=${y#./}
    if [ -z "$y" ] || [ -d "$y" ]; then
      local _out
      _out=$(_cb_subtree "$y") || return 1
      while IFS= read -r t; do targets+=("$t"); done <<< "$_out"
      continue
    fi
    local row
    row=$(_cb_resolve "$x") || return 1
    targets+=("${row%%$'\t'*}")
  done
  [ ${#targets[@]} -gt 0 ] || { echo "cb: no target given" >&2; return 1; }
  cmake --build "$_cb_build" --target "${targets[@]}" ${flags:+"${flags[@]}"}
}

#!/usr/bin/env bash
# cb_test.sh — functional test for cb (cmake/tools/cb.sh).
#
# Builds a throwaway mini cpcode checkout (git init + this repo's real
# CMakeLists.txt + cmake/) in a mktemp dir, sources the real cb.sh and
# exercises every verb:
#   name resolution  bare stem / slash full / slash suffix / dotted legacy /
#                    cwd prefix (beats ambiguity) / ambiguity listing (slash
#                    names) / did-you-mean / new-cpp reconfigure-retry
#   build            single, multi + flag passthrough, dir aggregate, `cb .`
#   run              stdin + argv passthrough, stdout/exit code, legacy
#                    `cb run-X`, rejects dir aggregate and no-main objects
#   test             AC/WA judged, no-samples error, dir aggregate
#   new              scaffold, --stress skeletons, refuses overwrite
#   stress           single-name auto trio + explicit trio
#   bridge           fifo round-trip (asserts interaction.log content)
#   cfg / help
#
# The user's own build trees are never touched: CP_BUILD_DIR pins a tree
# inside the scratch repo. Extra args go to the initial cmake configure,
# e.g.  bash cmake/tools/cb_test.sh -G Ninja
# Exit 0 = all green.

set -u
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
SCRATCH=$(mktemp -d "${TMPDIR:-/tmp}/cb_test.XXXXXX") || exit 2
export CP_BUILD_DIR="$SCRATCH/build"
trap 'rm -rf "$SCRATCH"' EXIT
PASS=0 FAIL=0

ok()  { PASS=$((PASS+1)); printf 'ok   - %s\n' "$1"; }
bad() { FAIL=$((FAIL+1)); printf 'FAIL - %s\n' "$1"; }

# verdict <desc> <ok|fail> <pattern> <cmd...>
#   rc must match the want, and combined output must contain pattern.
verdict() {
  local d=$1 want=$2 p=$3; shift 3
  local o r
  o=$("$@" 2>&1); r=$?
  if [ "$want" = ok ] && [ $r -ne 0 ]; then bad "$d (rc=$r, wanted 0)"; return; fi
  if [ "$want" = fail ] && [ $r -eq 0 ]; then bad "$d (rc=0, wanted failure)"; return; fi
  if printf '%s' "$o" | grep -q -- "$p"; then ok "$d"; else
    bad "$d (pattern '$p' missing; got: $(printf '%s' "$o" | head -2 | tr '\n' ' '))"
  fi
}
succeeds() { local d=$1; shift; verdict "$d" ok "" "$@"; }
fails()    { local d=$1; shift; verdict "$d" fail "" "$@"; }

# ---- scratch mini-repo ------------------------------------------------------
git init -q "$SCRATCH" || exit 2
cp "$ROOT/CMakeLists.txt" "$SCRATCH/"
cp -R "$ROOT/cmake" "$SCRATCH/cmake"
mkdir -p "$SCRATCH/t/add/samples" "$SCRATCH/t/echo" "$SCRATCH/t/stress" \
         "$SCRATCH/t/x1" "$SCRATCH/t/x2" "$SCRATCH/t/ich"

cat > "$SCRATCH/t/add/sum.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(){ long long a,b; cin>>a>>b; cout<<a+b<<"\n"; }
EOF
printf '2 3\n'   > "$SCRATCH/t/add/samples/sum_1.in";  printf '5\n'   > "$SCRATCH/t/add/samples/sum_1.out"
printf '10 20\n' > "$SCRATCH/t/add/samples/sum_2.in";  printf '999\n' > "$SCRATCH/t/add/samples/sum_2.out"   # WA on purpose

cat > "$SCRATCH/t/echo/show.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    for (int i = 1; i < argc; i++) cout << "argv:" << argv[i] << "\n";
    string line;
    while (getline(cin, line)) cout << "stdin:" << line << "\n";
}
EOF

printf 'int f() { return 42; }\n' > "$SCRATCH/nomain.cpp"    # root-level, no main()

cat > "$SCRATCH/t/stress/zap.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(){ long long a,b,s=0; cin>>a>>b; for (long long i=a;i<=b;i++) s+=i; cout<<s<<"\n"; }
EOF
cat > "$SCRATCH/t/stress/zap_brute.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(){ long long a,b; cin>>a>>b; cout << (a+b)*(b-a+1)/2 << "\n"; }
EOF
cat > "$SCRATCH/t/stress/zap_gen.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    unsigned s = argc > 1 ? (unsigned)atoi(argv[1]) : 0;
    mt19937 rng(s);
    long long a = rng() % 50, b = a + rng() % 50;
    cout << a << " " << b << "\n";
}
EOF

printf '#include <bits/stdc++.h>\nint main(){return 0;}\n' > "$SCRATCH/t/x1/dup.cpp"
printf '#include <bits/stdc++.h>\nint main(){return 0;}\n' > "$SCRATCH/t/x2/dup.cpp"

cat > "$SCRATCH/t/ich/asker.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(){ cout << "PING\n" << flush; string s; getline(cin, s); cout << "PONG " << s << "\n" << flush; }
EOF
cat > "$SCRATCH/t/ich/answer.cpp" <<'EOF'
#include <bits/stdc++.h>
using namespace std;
int main(){ string s; getline(cin, s); cout << "OK-" << s << "\n" << flush; }
EOF

# initial configure with any user args (-G Ninja ...); cb bootstrap skips then
cmake -S "$SCRATCH" -B "$CP_BUILD_DIR" "$@" >/dev/null 2>&1 \
  || { echo "cb_test: initial cmake configure failed" >&2; exit 2; }

. "$ROOT/cmake/tools/cb.sh"
cd "$SCRATCH" || exit 2

# ---- help -------------------------------------------------------------------
verdict "help lists run subcommand"  ok 'cb run <target>' cb help
succeeds "bare cb prints help"       cb

# ---- build: name forms + bootstrap -------------------------------------------
succeeds "first cb bootstraps + builds bare stem"  cb sum
succeeds "slash full name (t/add/sum)"             cb t/add/sum
succeeds "slash suffix (add/sum)"                  cb add/sum
succeeds "dotted legacy name (t.add.sum)"          cb t.add.sum
succeeds "multi target + flag passthrough"         cb sum show -j 2
[ -x "$CP_BUILD_DIR/bin/t/add/sum" ] && ok "binary lands in bin/t/add/sum" \
                                       || bad "binary lands in bin/t/add/sum"
succeeds "object lib (no main) compiles"           cb nomain

# ---- run ----------------------------------------------------------------------
out=$(printf 'x\ny\n' | cb run show hello 2>&1)
if printf '%s' "$out" | grep -q argv:hello && printf '%s' "$out" | grep -q stdin:x \
   && printf '%s' "$out" | grep -q stdin:y; then ok "run: argv + stdin passthrough"
else bad "run: argv + stdin passthrough (got: $out)"; fi
out=$(printf '3 4\n' | cb run sum 2>/dev/null)
[ "$out" = "7" ] && ok "run: clean stdout (build noise on stderr only)" \
                 || bad "run: clean stdout (got: $out)"
out=$(printf '5 6\n' | cb run-sum 2>/dev/null)
[ "$out" = "11" ] && ok "run: legacy cb run-sum still works" \
                    || bad "run: legacy cb run-sum still works (got: $out)"
verdict "run rejects directory aggregate" fail 'directory aggregate' cb run t/add
verdict "run rejects no-main object"      fail 'no main'             cb run nomain

# ---- test ---------------------------------------------------------------------
verdict "test: failing case reported"      fail 'sum_2'    cb test t/add
verdict "test: passing case reported"      fail 'sum_1'    cb test t/add
verdict "test: WA makes rc nonzero"        fail 'Failed'   cb test t/add
verdict "test: no samples errors out"      fail 'no samples' cb test show
verdict "test: dir aggregate, no samples"  fail 'no samples' cb test t/stress

# ---- new + reconfigure-retry ----------------------------------------------------
succeeds "cb new scaffolds (nested path)"  cb new t/madeup/zz
[ -f "$SCRATCH/t/madeup/zz.cpp" ] && ok "cb new created t/madeup/zz.cpp" \
                                     || bad "cb new created t/madeup/zz.cpp"
verdict "cb new refuses overwrite"  fail 'already exists'  cb new t/add/sum
succeeds "new cpp builds after auto-reconfigure"  cb zz

# ---- ambiguity / prefix / suggestions --------------------------------------------
verdict "ambiguous stem is rejected"        fail 'ambiguous'  cb dup
verdict "ambiguity lists slash candidate 1" fail 't/x1/dup'  cb dup
verdict "ambiguity lists slash candidate 2" fail 't/x2/dup'  cb dup
po=$( cd t/x1 && cb dup 2>&1 ) && ok "cwd prefix beats ambiguity" \
  || bad "cwd prefix beats ambiguity (got: $(printf '%s' "$po" | head -3 | tr '\n' ' '))"
verdict "did-you-mean fires"          fail 'did you mean'  cb sun
verdict "did-you-mean names sum"      fail 'sum'           cb sun
verdict "did-you-mean shows slash path" fail '(t/add/sum)' cb sun

# ---- aggregates / subtree ----------------------------------------------------------
succeeds "directory aggregate build"  cb t/stress
( cd t/stress && cb . >/dev/null 2>&1 ) \
  && ok "cb . builds the subtree" || bad "cb . builds the subtree"

# ---- stress -------------------------------------------------------------------------
succeeds "stress: single-name trio"  cb stress zap 30 5
succeeds "stress: explicit trio (slash names)"  \
         cb stress t/stress/zap_gen t/stress/zap_brute t/stress/zap 10 5

# ---- bridge ---------------------------------------------------------------------------
rm -f interaction.log
bro=$(cb bridge asker answer 2>&1); brc=$?
if grep -q 'PONG OK-PING' interaction.log 2>/dev/null; then
  ok "bridge: fifo round-trip in interaction.log"
else
  bad "bridge: round-trip missing (rc=$brc, out: $(printf '%s' "$bro" | head -2 | tr '\n' ' '))"
fi

# ---- cfg ---------------------------------------------------------------------------------
succeeds "cb cfg reconfigures"  cb cfg

# ---- summary ------------------------------------------------------------------------------
echo "--------------------------------------------------"
echo "cb_test: $PASS passed, $FAIL failed  (build tree: $CP_BUILD_DIR)"
[ $FAIL -eq 0 ]

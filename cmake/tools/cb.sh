# cb — short-name front for the cpcode CMake workflow ("cmake build", kept
# two keys on purpose). Optional convenience; pure
# `cmake --build -t <full.name>` keeps working without it.
#
# Usage:
#   source cmake/tools/cb.sh
#   cd cf/contest/2003
#   cb A / cb run-A / cb test-A     # build / run (stdin passthrough) / judge samples
#   cb A B C -j 8                   # several targets, flags pass through
#   cb 2003 / cb .                  # directory aggregate / subtree, recursively
#   cb new A [--stress]             # scaffold A.cpp (+ A_gen/A_brute skeletons)
#   cb stress A [iters] [tl]        # one-name duel (uses A_gen/A_brute)
#   cb stress A_gen A_brute A 1000 10   # explicit trio: iters, tl
#   cb cfg [-G Ninja ...]           # reconfigure the repo-root build tree
#   cb help | cb --help             # full reference
#
# Name resolution (per argument): exact full name in target-map.tsv ->
# cwd prefix (cf/contest/2003 + A -> cf.contest.2003.A) -> unique suffix
# match repo-wide; ambiguous bare names are rejected with candidates listed.
# A miss reconfigures once and retries, so freshly created cpps just work.
# Everything is located relative to `git rev-parse --show-toplevel`, so the
# script works in any clone and on any machine.

_cb_setup() {
  _cb_root=$(git rev-parse --show-toplevel 2>/dev/null) || { echo "cb: not inside a git repo" >&2; return 2; }
  # refuse foreign repos: cb would otherwise cmake-configure them by accident
  if [ ! -f "$_cb_root/cmake/add_problem.cmake" ] || [ ! -f "$_cb_root/CMakeLists.txt" ]; then
    echo "cb: '$_cb_root' is not a cpcode checkout — refusing to touch it" >&2
    return 2
  fi
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
  if [ ! -f "$root/cmake/add_problem.cmake" ]; then
    echo "cb: '$root' is not a cpcode checkout — refusing to touch it" >&2
    return 1
  fi
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
    _cb_suggest "$base"
  else
    echo "cb: '$base' is ambiguous, candidates:" >&2
    printf '%s\n' "$hit" | while IFS=$'\t' read -r t s; do echo "  $t   <- $s" >&2; done | head -8
  fi
  return 1
}

# _cb_suggest <name> — "did you mean" via edit distance <= 2 against stems.
_cb_suggest() {
  local q=$1
  awk -F'\t' -v q="$q" '
    function lev(a, b,   la, lb, i, j, prev, cur, cost, t) {
      la = length(a); lb = length(b)
      if (la == 0) return lb; if (lb == 0) return la
      for (j = 0; j <= lb; j++) prev[j] = j
      for (i = 1; i <= la; i++) {
        cur[0] = i
        for (j = 1; j <= lb; j++) {
          cost = substr(a, i, 1) != substr(b, j, 1)
          t = prev[j-1] + cost
          if (prev[j] + 1 < t) t = prev[j] + 1
          if (cur[j-1] + 1 < t) t = cur[j-1] + 1
          cur[j] = t
        }
        for (j = 0; j <= lb; j++) prev[j] = cur[j]
      }
      return prev[lb]
    }
    {
      s = $1; sub(/\.cpp$/, "", s); ns = split(s, seg, "/"); stem = seg[ns]
      if (stem == "" || seen[stem]++) next
      d = lev(q, stem)
      if (d <= 2 && d < length(q) && d < length(stem)) print d "\t" stem "\t" $2
    }' "$_cb_map" | sort -t$'\t' -k1,1n | head -3 | while IFS=$'\t' read -r d stem tgt; do
      echo "  did you mean: $stem   ($tgt)" >&2
    done
}

# _cb_bin <source-path> -> binary path inside the build tree
_cb_bin() {
  local src=$1 d n
  d=$(dirname "$src"); n=$(basename "$src" .cpp)
  printf '%s/bin/%s/%s\n' "$_cb_build" "$d" "$n"
}

_cb_stress() {
  _cb_setup || return 1
  local g b s
  # single-name form: cb stress A [iters] [tl]  ->  A_gen + A_brute + A
  if [ $# -lt 3 ] || [ -z "$(printf '%s' "$2" | tr -d '0-9')" ]; then
    local name=$1; shift
    [ -n "$name" ] || { echo "usage: cb stress <sol> [iters] [tl]  |  cb stress <gen> <brute> <sol> [iters] [tl]" >&2; return 1; }
    local rs
    rs=$(_cb_resolve "$name") || return 1
    local st=${rs%%$'\t'*}
    local rg rb
    rg=$(_cb_lookup "${st}_gen") || { echo "cb: no '${name}_gen' target; scaffold via: cb new $name --stress" >&2; return 1; }
    rb=$(_cb_lookup "${st}_brute") || { echo "cb: no '${name}_brute' target; scaffold via: cb new $name --stress" >&2; return 1; }
    g=$rg b=$rb s=$rs
  else
    g=$1 b=$2 s=$3; shift 3
    local rg rb rs
    rg=$(_cb_resolve "$g") || return 1
    rb=$(_cb_resolve "$b") || return 1
    rs=$(_cb_resolve "$s") || return 1
    g=$rg b=$rb s=$rs
  fi
  cmake --build "$_cb_build" --target "${g%%$'\t'*}" "${b%%$'\t'*}" "${s%%$'\t'*}" || return 1
  cmake -P "$_cb_root/cmake/stress.cmake" \
    "$(_cb_bin "${g#*$'\t'}")" \
    "$(_cb_bin "${b#*$'\t'}")" \
    "$(_cb_bin "${s#*$'\t'}")" "$@"
}

_cb_help() {
  cat <<'EOF'
cb - short-name front for the cpcode CMake workflow
    (name = "cmake build"; two keys on purpose)

usage:
  cb <target>... [flags]          build targets (short names ok)
  cb <dir> | cb .                 build every cpp under a directory, recursively
  cb run-<target>                 run, stdin passthrough (interactive / < in.txt)
  cb test-<target>                build + judge samples (AC/WA/TLE/RE)
  cb stress <sol> [iters] [tl]    duel <sol>_gen + <sol>_brute + <sol>
  cb stress <gen> <brute> <sol> [iters] [tl]
                                  explicit trio
  cb new [--stress] <name>        scaffold <name>.cpp from cmake/tools/sol.cpp
                                  (--stress adds <name>_gen.cpp/_brute.cpp)
  cb cfg [cmake args...]          reconfigure the repo-root build tree
  cb help | -h | --help           this help

a whole problem, from scratch:
  cb new A --stress       scaffold A.cpp + A_gen.cpp + A_brute.cpp
  ... edit the three files ...
  cb run-A                try sample input by hand
  cb test-A               judge samples/ (A_1.in + A_1.out pairs)
  cb stress A 1000        randomized duel against the brute force

name resolution (per argument):
  full target name -> cwd prefix (cf/contest + 2003.A) -> unique suffix
  repo-wide; ambiguous names list candidates.
  A miss reconfigures once and retries: new cpps need no ceremony.
  cb also bootstraps a missing build tree on first use.

cleanup (plain cmake, no cb needed):
  cmake --build build -t clean      # remove build products
  cmake -E rm -rf build             # full reset

build tree: $CP_BUILD_DIR, else build/, else build-ninja/
prereq: inside a cpcode checkout (detected via cmake/add_problem.cmake;
        foreign git repos are refused without side effects), cmake >= 3.20,
        C++ compiler, bash/zsh, sourced cb.sh
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
  [ -f "$root/cmake/add_problem.cmake" ] || { echo "cb: '$root' is not a cpcode checkout — refusing to touch it" >&2; return 1; }
  local tpl="${CP_TEMPLATE:-$root/cmake/tools/sol.cpp}"
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
    for sk in gen:tools/gen.cpp brute:tools/brute.cpp; do
      local base="$name"_${sk%%:*}
      local src=$root/cmake/${sk#*:}
      if [ -e "$base.cpp" ]; then
        echo "exists:  $base.cpp (kept)"
      elif [ -f "$src" ]; then
        cp "$src" "$base.cpp"
        echo "created: $base.cpp   (skeleton)"
      fi
    done
  fi
  echo "next: cb $name | cb run-$name | cb test-$name${stress:+ | cb stress ${name}_gen ${name}_brute $name}"
}

cb() {
  case "$1" in
    stress) shift; _cb_stress "$@"; return ;;
    cfg)    shift; _cb_cfg "$@"; return ;;
    new)    shift; _cb_new "$@"; return ;;
    -h|--help|help|"") _cb_help; return ;;
  esac
  _cb_setup
  case $? in
    0) ;;
    2) return 1 ;;                                    # wrong repo: no bootstrap
    *) _cb_cfg >/dev/null 2>&1 && _cb_setup || { echo "cb: no build tree, run: cb cfg" >&2; return 1; } ;;
  esac
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

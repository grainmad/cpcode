# stress.cmake — randomized duel testing (对拍): gen vs brute vs sol.
#
# Usage (from the repo root, after building the three targets):
#   cmake -P cmake/stress.cmake <gen> <brute> <sol> [iters=1000] [tl_sec=10]
# Example:
#   cmake --build build -t cf.contest.2003.A -t my.gen -t my.brute
#   cmake -P cmake/stress.cmake build/bin/my/gen build/bin/my/brute \
#                              build/bin/cf/contest/2003/A 1000 10
#
# Contract:
#   gen   : prints one test to stdout; argv[1] = iteration index (usable as seed)
#   brute : reads test on stdin, prints reference answer
#   sol   : reads test on stdin, prints candidate answer
# Outputs are compared with the same normalization as judge.cmake (trailing
# whitespace / blank lines). On mismatch the input and both outputs are kept in
# build/stress/fail_<n>/ and the script exits non-zero.
#
# Known limitation: execute_process(TIMEOUT) kills only the direct child, not
# its process tree. Competitive-programming binaries don't fork, so this is
# fine here.

if(NOT DEFINED CMAKE_ARGV5)
  message(FATAL_ERROR
    "usage: cmake -P stress.cmake <gen> <brute> <sol> [iters=1000] [tl_sec=10]
   each of gen/brute/sol: a binary path (build/bin/...) or a target name
   (cf.contest.2003.A), resolved via <build>/target-map.tsv")
endif()

set(gen   "${CMAKE_ARGV3}")
set(brute "${CMAKE_ARGV4}")
set(sol   "${CMAKE_ARGV5}")
set(iters 1000)
if(NOT "${CMAKE_ARGV6}" STREQUAL "")
  set(iters "${CMAKE_ARGV6}")
endif()
set(tl 10)
if(NOT "${CMAKE_ARGV7}" STREQUAL "")
  set(tl "${CMAKE_ARGV7}")
endif()

# Resolve a binary path or a target name (looked up in target-map.tsv) to the
# real executable. Build dir: $ENV{CP_BUILD_DIR}, else ./build, else ./build-ninja.
function(_cp_resolve outvar arg)
  if(EXISTS "${arg}")
    set(${outvar} "${arg}" PARENT_SCOPE)
    return()
  endif()
  # repo root = parent of this script (cmake/stress.cmake); works from any cwd
  get_filename_component(_root "${CMAKE_ARGV2}" DIRECTORY)
  get_filename_component(_root "${_root}" DIRECTORY)
  get_filename_component(_root "${_root}" ABSOLUTE)
  # script mode has no CMAKE_CURRENT_BINARY_DIR — ask the shell where we are
  execute_process(COMMAND pwd OUTPUT_VARIABLE _cwd OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(_dirs "")
  if(NOT "$ENV{CP_BUILD_DIR}" STREQUAL "")
    list(APPEND _dirs "$ENV{CP_BUILD_DIR}")
  endif()
  list(APPEND _dirs "${_root}/build" "${_root}/build-ninja" "${_cwd}/build")
  foreach(_bdir IN LISTS _dirs)
    set(_map "${_bdir}/target-map.tsv")
    if(NOT EXISTS "${_map}")
      continue()
    endif()
    set(_found "")
    set(_sdirs "")
    file(STRINGS "${_map}" _lines)
    foreach(_line IN LISTS _lines)
      if(_line STREQUAL "" OR _line MATCHES "^#")
        continue()
      endif()
      string(REPLACE "\t" ";" _cols "${_line}")
      list(LENGTH _cols _ncols)
      if(_ncols LESS 3)
        continue()
      endif()
      list(GET _cols 1 _tgt)
      list(GET _cols 0 _src)
      list(GET _cols 2 _kind)
      if(_kind STREQUAL "dir")
        continue()
      endif()
      # exact name, or a short name that this target ends with (run from the
      # problem directory: `... stress.cmake gen brute sol`)
      string(REGEX REPLACE "\\." "\\\\." _esc "${arg}")
      if(NOT "${_tgt}" STREQUAL "${arg}" AND NOT _tgt MATCHES "\\.${_esc}$")
        continue()
      endif()
      get_filename_component(_stem "${_src}" NAME_WE)
      get_filename_component(_sdir "${_src}" DIRECTORY)
      set(_bin "${_bdir}/bin/${_sdir}/${_stem}")
      if(EXISTS "${_bin}")
        list(APPEND _found "${_bin}")
        list(APPEND _sdirs "${_sdir}")
      endif()
    endforeach()
    if(_found)
      list(LENGTH _found _nf)
      if(_nf GREATER 1)
        # several targets end with this name: prefer the one in the cwd
        file(RELATIVE_PATH _relcwd "${_root}" "${_cwd}")
        set(_pick "")
        set(_i 0)
        foreach(_sd IN LISTS _sdirs)
          if("${_sd}" STREQUAL "${_relcwd}")
            list(APPEND _pick "${_i}")
          endif()
          math(EXPR _i "${_i} + 1")
        endforeach()
        list(LENGTH _pick _np)
        if(NOT _np EQUAL 1)
          message(FATAL_ERROR "'${arg}' is ambiguous: ${_found}")
        endif()
        list(GET _pick 0 _idx)
        list(GET _found ${_idx} _bin)
        set(${outvar} "${_bin}" PARENT_SCOPE)
        return()
      endif()
      list(GET _found 0 _bin)
      set(${outvar} "${_bin}" PARENT_SCOPE)
      return()
    endif()
  endforeach()
  message(FATAL_ERROR
    "${arg}: not a file path, and no built binary for this target in build//build-ninja/
(build it first: cmake --build build -t ${arg}; or set CP_BUILD_DIR)")
endfunction()

foreach(b IN ITEMS gen brute sol)
  _cp_resolve(${b} "${${b}}")
endforeach()

# artifacts live under the build tree that produced the binaries
string(FIND "${gen}" "/bin/" _binpos)
if(_binpos GREATER -1)
  string(SUBSTRING "${gen}" 0 ${_binpos} outroot)
else()
  set(outroot "${CMAKE_CURRENT_BINARY_DIR}")
endif()
set(stressdir "${outroot}/stress")
file(MAKE_DIRECTORY "${stressdir}")
set(lastinput "${stressdir}/last_input.txt")

if("$ENV{NO_COLOR}" STREQUAL "")
  string(ASCII 27 _esc)
  set(c_red "${_esc}[0;31m")
  set(c_grn "${_esc}[0;32m")
  set(c_ylw "${_esc}[0;33m")
  set(c_rst "${_esc}[0m")
endif()

function(_cp_norm outvar content)
  string(REPLACE "\r\n" "\n" c "${content}")
  string(REGEX REPLACE "[ \t]+\n" "\n" c "${c}")
  string(REGEX REPLACE "[ \t]+$" "" c "${c}")
  string(REGEX REPLACE "\n+$" "" c "${c}")
  set(${outvar} "${c}" PARENT_SCOPE)
endfunction()

message(STATUS "${c_ylw}[stress]${c_rst} gen=${gen}")
message(STATUS "${c_ylw}[stress]${c_rst} brute=${brute}  sol=${sol}")
message(STATUS "${c_ylw}[stress]${c_rst} iters=${iters} tl=${tl}s  cases -> ${stressdir}")

foreach(i RANGE 1 ${iters})
  execute_process(COMMAND "${gen}" "${i}" OUTPUT_VARIABLE data RESULT_VARIABLE rc TIMEOUT ${tl})
  if("${rc}" STREQUAL "Process terminated due to timeout")
    message(FATAL_ERROR "${c_red}[stress] gen TLE at iter ${i}${c_rst}")
  endif()
  if(NOT rc EQUAL 0)
    message(FATAL_ERROR "${c_red}[stress] gen RE (exit ${rc}) at iter ${i}${c_rst}")
  endif()
  file(WRITE "${lastinput}" "${data}")

  execute_process(COMMAND "${brute}" INPUT_FILE "${lastinput}"
    OUTPUT_VARIABLE bout RESULT_VARIABLE brc TIMEOUT ${tl})
  if("${brc}" STREQUAL "Process terminated due to timeout")
    message(FATAL_ERROR "${c_red}[stress] brute TLE at iter ${i}, input kept: ${lastinput}${c_rst}")
  endif()
  if(NOT brc EQUAL 0)
    message(FATAL_ERROR "${c_red}[stress] brute RE (exit ${brc}) at iter ${i}, input kept: ${lastinput}${c_rst}")
  endif()

  execute_process(COMMAND "${sol}" INPUT_FILE "${lastinput}"
    OUTPUT_VARIABLE sout RESULT_VARIABLE src TIMEOUT ${tl})
  if("${src}" STREQUAL "Process terminated due to timeout")
    message(FATAL_ERROR "${c_red}[stress] sol TLE at iter ${i}, input kept: ${lastinput}${c_rst}")
  endif()
  if(NOT src EQUAL 0)
    message(FATAL_ERROR "${c_red}[stress] sol RE (exit ${src}) at iter ${i}, input kept: ${lastinput}${c_rst}")
  endif()

  _cp_norm(bn "${bout}")
  _cp_norm(sn "${sout}")
  if(NOT bn STREQUAL sn)
    set(fdir "${stressdir}/fail_${i}")
    file(MAKE_DIRECTORY "${fdir}")
    file(COPY_FILE "${lastinput}" "${fdir}/input.txt")
    file(WRITE "${fdir}/brute.out" "${bout}")
    file(WRITE "${fdir}/sol.out" "${sout}")
    execute_process(COMMAND diff -u "${fdir}/brute.out" "${fdir}/sol.out"
      OUTPUT_VARIABLE d ERROR_VARIABLE d RESULT_VARIABLE _ignored)
    message(FATAL_ERROR
      "${c_red}[stress] WA at iter ${i}${c_rst}\ninput : ${fdir}/input.txt\n${d}")
  endif()

  math(EXPR _hundred "${i} % 100")
  if(_hundred EQUAL 0)
    message(STATUS "${c_grn}[stress] ${i}/${iters} passed${c_rst}")
  endif()
endforeach()

message(STATUS "${c_grn}[stress] all ${iters} iterations passed${c_rst}")

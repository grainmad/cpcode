# judge.cmake — run one test case and compare against the answer file.
#
# Usage: cmake -P judge.cmake <exe> <input> <answer> [timeout_sec]
#   (registered by add_test in add_problem.cmake; manual use is fine too)
# Verdict: AC -> exit 0; WA / TLE / RE -> FATAL_ERROR (non-zero exit).
#
# Comparison follows competitive-programming convention: normalize CRLF,
# trailing whitespace on each line, and trailing blank lines before comparing.

if(NOT DEFINED CMAKE_ARGV5)
  message(FATAL_ERROR "usage: cmake -P judge.cmake <exe> <input> <answer> [timeout_sec]")
endif()

set(exe "${CMAKE_ARGV3}")
set(in "${CMAKE_ARGV4}")
set(ans "${CMAKE_ARGV5}")
set(tl 10)
if(NOT "${CMAKE_ARGV6}" STREQUAL "")
  set(tl "${CMAKE_ARGV6}")
endif()

foreach(f exe in ans)
  if(NOT EXISTS "${${f}}")
    message(FATAL_ERROR "${f} not found: ${${f}}")
  endif()
endforeach()

execute_process(COMMAND "${exe}"
  INPUT_FILE "${in}"
  OUTPUT_VARIABLE got
  ERROR_VARIABLE err
  RESULT_VARIABLE rc
  TIMEOUT ${tl})

if("${rc}" STREQUAL "Process terminated due to timeout")
  message(FATAL_ERROR "TLE  ${in}  (>${tl}s)")
endif()
if(NOT rc EQUAL 0)
  message(FATAL_ERROR "RE   ${in}  (exit code ${rc})\nstderr:\n${err}")
endif()

function(_cp_norm outvar content)
  string(REPLACE "\r\n" "\n" c "${content}")
  string(REGEX REPLACE "[ \t]+\n" "\n" c "${c}")
  string(REGEX REPLACE "[ \t]+$" "" c "${c}")
  string(REGEX REPLACE "\n+$" "" c "${c}")
  set(${outvar} "${c}" PARENT_SCOPE)
endfunction()

file(READ "${ans}" want)
_cp_norm(want_n "${want}")
_cp_norm(got_n "${got}")

if(got_n STREQUAL want_n)
  message(STATUS "AC   ${in}")
  return()
endif()

# WA: keep the failing input and both outputs next to the build tree, then show
# a unified diff of the raw files for eyeballing.
string(MD5 tag "${in}")
set(dir "${CMAKE_CURRENT_BINARY_DIR}/judge-fail/${tag}")
file(MAKE_DIRECTORY "${dir}")
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different "${in}" "${dir}/input.txt")
file(WRITE "${dir}/actual.out" "${got}")
file(WRITE "${dir}/expected.out" "${want}")
execute_process(COMMAND diff -u "${dir}/expected.out" "${dir}/actual.out"
  RESULT_VARIABLE _ignored OUTPUT_VARIABLE _diffout ERROR_VARIABLE _diffout)
message(STATUS "WA   ${in}\n${_diffout}")
message(FATAL_ERROR "WA   ${in}  (artifacts: ${dir})")

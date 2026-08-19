# cp_add_problem(<src>) — turn one .cpp into build/run/judge targets.
#
# Targets (all EXCLUDE_FROM_ALL: bare `cmake --build build` is a no-op):
#   <name>        executable; OBJECT library instead when the file has no main()
#   run-<name>    run the executable, stdin inherited (make recipe / ninja console pool),
#                 working directory = the source directory (freopen-friendly)
#   test-<name>   build + run all discovered samples through ctest
#                 (only created when at least one sample is found)
# Tests:
#   judge.<name>.<case>    one sample, judged by cmake/judge.cmake (AC/WA/TLE/RE)
#
# <name> = repo-relative path with '/'->'.', '.cpp' stripped, bytes outside
# [A-Za-z0-9_.+-] -> '_' (space and CJK filenames), collisions get '.2', '.3', ...
# The authoritative path<->target mapping is dumped to build/target-map.tsv
# (CMake is the single source of truth for the mangling — never re-derive it elsewhere).

# cp_add_problem(<src>) — turn one .cpp into build/run/judge targets.
#
# Targets (all EXCLUDE_FROM_ALL: bare `cmake --build build` is a no-op):
#   <name>        executable; OBJECT library instead when the file has no main()
#   run-<name>    run the executable, stdin inherited (make recipe / ninja console pool),
#                 working directory = the source directory (freopen-friendly)
#   test-<name>   build + run all discovered samples through ctest
#                 (only created when at least one sample is found)
# Directory aggregate (created by cp_add_dir_targets, called from CMakeLists):
#   <dir>         one target per directory that directly contains .cpp files,
#                 e.g. tmp.stress builds gen/brute/sol, cf.contest.2003 builds A..D2
# Tests:
#   judge.<name>.<case>    one sample, judged by cmake/judge.cmake (AC/WA/TLE/RE)
#
# <name> = repo-relative path with '/'->'.', '.cpp' stripped, bytes outside
# [A-Za-z0-9_.+-] -> '_' (space and CJK filenames), collisions get '.2', '.3', ...
# The authoritative path<->target mapping is dumped to build/target-map.tsv
# (CMake is the single source of truth for the mangling — never re-derive it elsewhere).

function(cp_add_problem src)
  file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}" "${src}")

  # --- unique, generator-safe target name ---
  string(REPLACE "/" "." name "${rel}")
  string(REGEX REPLACE "\\.cpp$" "" name "${name}")
  string(REGEX REPLACE "[^A-Za-z0-9_.+-]" "_" name "${name}")
  set(candidate "${name}")
  set(n 1)
  get_property(taken GLOBAL PROPERTY "cp_taken_${candidate}")
  while(taken)
    math(EXPR n "${n} + 1")
    set(candidate "${name}.${n}")
    get_property(taken GLOBAL PROPERTY "cp_taken_${candidate}")
  endwhile()
  set_property(GLOBAL PROPERTY "cp_taken_${candidate}" TRUE)
  set(name "${candidate}")

  get_filename_component(stem "${src}" NAME_WE)
  get_filename_component(dir "${src}" DIRECTORY)
  file(RELATIVE_PATH rdir "${CMAKE_SOURCE_DIR}" "${dir}")

  # --- files without main(): compile-check only, they cannot link ---
  file(READ "${src}" _content)
  if(NOT _content MATCHES "(int|signed|void)[ \t\r\n]*main[ \t]*\\(")
    add_library(${name} OBJECT EXCLUDE_FROM_ALL "${src}")
    set_property(GLOBAL APPEND PROPERTY cp_manifest "${rel}\t${name}\tobject")
    set_property(GLOBAL APPEND PROPERTY cp_all_names ${name})
    string(REPLACE "/" "." dirname "${rdir}")
    string(REGEX REPLACE "[^A-Za-z0-9_.+-]" "_" dirname "${dirname}")
    if(NOT dirname STREQUAL "")
      set_property(GLOBAL APPEND PROPERTY "cp_dirdeps_${dirname}" ${name})
      set_property(GLOBAL APPEND PROPERTY cp_dirs ${dirname})
    endif()
    return()
  endif()

  add_executable(${name} EXCLUDE_FROM_ALL "${src}")
  set_target_properties(${name} PROPERTIES
    OUTPUT_NAME "${stem}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${rdir}")
  set_property(GLOBAL APPEND PROPERTY cp_manifest "${rel}\t${name}\texe")
  set_property(GLOBAL APPEND PROPERTY cp_all_names ${name})
  # remember the owning directory for the per-directory aggregate target
  string(REPLACE "/" "." dirname "${rdir}")
  string(REGEX REPLACE "[^A-Za-z0-9_.+-]" "_" dirname "${dirname}")
  if(NOT dirname STREQUAL "")
    set_property(GLOBAL APPEND PROPERTY "cp_dirdeps_${dirname}" ${name})
    set_property(GLOBAL APPEND PROPERTY cp_dirs ${dirname})
  endif()

  # --- interactive/redirected run: stdin is inherited from `cmake --build` ---
  add_custom_target(run-${name}
    COMMAND ${CMAKE_COMMAND} -E echo "run: $<TARGET_FILE:${name}> (cwd: ${rdir})"
    COMMAND $<TARGET_FILE:${name}>
    DEPENDS ${name}
    WORKING_DIRECTORY "${dir}"
    USES_TERMINAL VERBATIM)

  # --- sample discovery: {stem}.in, {stem}_*.in, {stem}-*.in next to the source
  #    or under samples/ (the committed convention); legacy in.txt only when the
  #    directory holds exactly one .cpp (single-problem directories) ---
  file(GLOB _cases LIST_DIRECTORIES false
    "${dir}/${stem}.in"
    "${dir}/${stem}_*.in"
    "${dir}/${stem}-*.in"
    "${dir}/samples/${stem}.in"
    "${dir}/samples/${stem}_*.in"
    "${dir}/samples/${stem}-*.in")
  file(GLOB _dircpps LIST_DIRECTORIES false "${dir}/*.cpp")
  list(LENGTH _dircpps _ncpp)
  if(_ncpp EQUAL 1)
    foreach(_legacy in.txt samples/in.txt)
      if(EXISTS "${dir}/${_legacy}")
        list(APPEND _cases "${dir}/${_legacy}")
      endif()
    endforeach()
  endif()

  set(_tests 0)
  foreach(case IN LISTS _cases)
    string(REGEX REPLACE "\\.in$" ".out" want "${case}")
    if(NOT EXISTS "${want}")
      continue()
    endif()
    get_filename_component(cname "${case}" NAME_WE)
    string(REGEX REPLACE "[^A-Za-z0-9_.+-]" "_" cname "${cname}")
    add_test(NAME judge.${name}.${cname}
      COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/judge.cmake
              $<TARGET_FILE:${name}> "${case}" "${want}" 10)
    set_tests_properties(judge.${name}.${cname} PROPERTIES TIMEOUT 60)
    math(EXPR _tests "${_tests} + 1")
  endforeach()

  # --- one-command test: builds the exe, then runs only this problem's cases ---
  if(_tests GREATER 0)
    string(REPLACE "." "[.]" rx "${name}")
    string(REPLACE "+" "[+]" rx "${rx}")
    add_custom_target(test-${name}
      COMMAND ${CMAKE_CTEST_COMMAND} --test-dir "${CMAKE_BINARY_DIR}"
              -R "^judge[.]${rx}[.]" --output-on-failure
      DEPENDS ${name}
      USES_TERMINAL VERBATIM)
  endif()
endfunction()

function(cp_write_target_manifest)
  get_property(lines GLOBAL PROPERTY cp_manifest)
  if(NOT lines)
    set(lines "")
  endif()
  list(JOIN lines "\n" body)
  file(WRITE "${CMAKE_BINARY_DIR}/target-map.tsv"
    "# repo-relative-source\ttarget\tkind\n${body}\n")
endfunction()

# One aggregate target per directory that directly contains .cpp files:
#   cmake --build build -t tmp.stress         -> gen + brute + sol
#   cmake --build build -t cf.contest.2003    -> A..D2
# A file target that squatted the name (e.g. cf/contest/2003.cpp) wins;
# in that rare case the directory aggregate is skipped with a notice.
function(cp_add_dir_targets)
  get_property(dirs GLOBAL PROPERTY cp_dirs)
  list(REMOVE_DUPLICATES dirs)
  foreach(dirname IN LISTS dirs)
    get_property(taken GLOBAL PROPERTY "cp_taken_${dirname}")
    if(taken)
      message(STATUS "directory aggregate '${dirname}' skipped: name taken by a file target")
      continue()
    endif()
    get_property(deps GLOBAL PROPERTY "cp_dirdeps_${dirname}")
    # (no ALL keyword => stays out of the default build, like everything else here)
    add_custom_target(${dirname} DEPENDS ${deps})
    set_property(GLOBAL APPEND PROPERTY cp_manifest "${dirname}/\t${dirname}\tdir")
  endforeach()
endfunction()

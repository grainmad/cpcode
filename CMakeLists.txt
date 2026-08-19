cmake_minimum_required(VERSION 3.20)
project(cpcode CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "build type" FORCE)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    # debugging build with sanitizers: cmake -B build-dbg -DCMAKE_BUILD_TYPE=Debug
    add_compile_options(-g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address,undefined)
  else()
    add_compile_options(-O2)
  endif()
endif()

# Toolchains without <bits/stdc++.h> (Apple clang / libc++) fall back to the
# bundled shim. On glibc/libstdc++ the native header exists and wins untouched.
include(CheckIncludeFileCXX)
set(CMAKE_REQUIRED_FLAGS "-std=c++17")
check_include_file_cxx("bits/stdc++.h" CP_HAVE_BITS_STDCXX)
unset(CMAKE_REQUIRED_FLAGS)
if(NOT CP_HAVE_BITS_STDCXX)
  message(STATUS "bits/stdc++.h not found -> using bundled shim cmake/compat/")
  include_directories(BEFORE "${CMAKE_SOURCE_DIR}/cmake/compat")
endif()

enable_testing()

# Restrict to one subtree for a slim, fast tree:
#   cmake -B build-fast -DCP_SCOPE=cf/contest/2003
set(CP_SCOPE "" CACHE STRING "restrict to a repo subtree, e.g. cf/contest/2003 (empty = whole repo)")

file(GLOB_RECURSE CP_SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "*.cpp")
# (list(FILTER)'s syntax changed across major CMake versions — plain
#  foreach+MATCHES behaves identically everywhere.)
set(_all "${CP_SOURCES}")
set(CP_SOURCES "")
if(CP_SCOPE)
  string(REPLACE "${CMAKE_SOURCE_DIR}/" "" CP_SCOPE_REL "${CP_SCOPE}")
endif()
foreach(_src IN LISTS _all)
  if(_src MATCHES "^${CMAKE_BINARY_DIR}/")
    continue()
  endif()
  if(CP_SCOPE AND NOT _src MATCHES "^${CMAKE_SOURCE_DIR}/${CP_SCOPE_REL}/")
    continue()
  endif()
  list(APPEND CP_SOURCES "${_src}")
endforeach()
list(SORT CP_SOURCES)
list(LENGTH CP_SOURCES CP_SOURCES_COUNT)

include(${CMAKE_SOURCE_DIR}/cmake/add_problem.cmake)
foreach(src IN LISTS CP_SOURCES)
  cp_add_problem("${src}")
endforeach()
cp_add_dir_targets()
cp_write_target_manifest()

# explicit full-regression entry (everything above is EXCLUDE_FROM_ALL,
# so a bare `cmake --build build` stays a cheap no-op)
get_property(CP_ALL_NAMES GLOBAL PROPERTY cp_all_names)
if(CP_ALL_NAMES)
  add_custom_target(all-problems DEPENDS ${CP_ALL_NAMES})
endif()

message(STATUS "cpcode: ${CP_SOURCES_COUNT} sources (target map: ${CMAKE_BINARY_DIR}/target-map.tsv)")

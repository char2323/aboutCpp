cmake_minimum_required(VERSION 3.16)
project(try)

if(NOT CMAKE_BUILD_TYPE)
  set(default_build_type "Debug")
  message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
  set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
  "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "try Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for try
set(try_Version_Major 0)
set(try_Version_Minor 1)
set(try_Version_Patch 0)
set(try_Version_Status "-dev")
set(PROJECT_VERSION
  "${try_Version_Major}.${try_Version_Minor}.${try_Version_Patch}${try_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")

add_executable(test test.cpp)

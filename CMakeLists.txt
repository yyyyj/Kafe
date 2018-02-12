cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)

project(Kafe)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "-std=c++14 -fpermissive -O3")
endif()

file(GLOB_RECURSE PG_UN "./kafe/*.hpp" "./tests.hpp")
file(GLOB_RECURSE HD_UN "./kafe/*.cpp" "./tests.cpp" "./main.cpp")

set_property(GLOBAL APPEND_STRING PROPERTY COMPILE_FLAGS -Wall)

include_directories(kafe/)

add_executable(Kafe ${PG_UN} ${HD_UN})
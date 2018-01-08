cmake_minimum_required(VERSION 3.6)
cmake_policy(SET CMP0015 NEW)

project(Kafe)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -O3")
endif()

file(GLOB_RECURSE PG_UN "${Kafe_SOURCE_DIR}/kafe/*.hpp" "${Kafe_SOURCE_DIR}/tests.hpp")
file(GLOB_RECURSE HD_UN "${Kafe_SOURCE_DIR}/kafe/*.cpp" "${Kafe_SOURCE_DIR}/tests.cpp" "${Kafe_SOURCE_DIR}/main.cpp")

set_property(GLOBAL APPEND_STRING PROPERTY COMPILE_FLAGS -Wall)

include_directories(kafe/)

add_executable(Kafe ${PG_UN} ${HD_UN})
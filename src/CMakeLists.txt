cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)
project(Kafe)

message(STATUS "Building project Kafe")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

ANTLR(INPUT Kafe.g4)

file(GLOB_RECURSE INCLUDE_FILES "kafe/*.hpp" "tests/*.hpp")
file(GLOB_RECURSE SRC_FILES "kafe/*.cpp" "tests/*.cpp" "main.cpp")

add_executable(Kafe main.cpp ${INCLUDE_FILES} ${SRC_FILES})
target_link_libraries(Kafe antlr4_shared)
link_directories(GLOB_RECURSE "${CMAKE_HOME_DIRECTORY}/dist")
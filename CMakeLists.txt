cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)

project(KafeBuilder)

# Build the ANTLR runtime.
add_subdirectory(${CMAKE_SOURCE_DIR}/antlr/cpp_runtime/)

include_directories(${CMAKE_SOURCE_DIR}/antlr/cpp_runtime/runtime/src)
include_directories(${CMAKE_SOURCE_DIR}/thirdparty)
include_directories(${CMAKE_SOURCE_DIR}/include)

#-------------------------------------------------------------------------------

add_subdirectory(src/kafe)
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Kafe)
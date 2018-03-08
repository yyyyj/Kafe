cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)

project(KafeBuilder)

# Build the ANTLR runtime.
add_subdirectory(${CMAKE_SOURCE_DIR}/antlr/cpp_runtime/)
include_directories(${CMAKE_SOURCE_DIR}/antlr/cpp_runtime/runtime/src)

# Generating the parser
message(STATUS "The grammar ${CMAKE_SOURCE_DIR}/grammar/Kafe.g4 should be now used to generate a new parser")
execute_process(
    COMMAND java -jar antlr/antlr-4.7.1-complete.jar -Dlanguage=Cpp -no-listener -no-visitor -o include/kafe/parser grammar/Kafe.g4
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

#-------------------------------------------------------------------------------

add_subdirectory(src/kafe)
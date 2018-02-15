cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Function
#   ANTLR(INPUT <input> (DEPENDENCIES <dependencies>))
#
# Description:
#   Take an ANTLR file and produce a CMake rule to generate the corresponding
#   C++ files.
#
# Notes:
#   The ANTLR file path must be relative to ${CMAKE_CURRENT_SOURCE_DIR}
#
# Example:
#   ANTLR(INPUT MyLexer.g4)
#   ANTLR(INPUT MyParser.g4 DEPENDENCIES MyLexer.cpp)
function(ANTLR)
  cmake_parse_arguments(ARGUMENTS "DEPENDENCIES" "INPUT" "" ${ARGN} )
  set(source ${ARGUMENTS_INPUT})
  set(dependencies ${ARGUMENTS_UNPARSED_ARGUMENTS})
  get_filename_component(source_filename ${CMAKE_CURRENT_SOURCE_DIR}/${source} NAME_WE)
  get_filename_component(source_src_dir  ${CMAKE_CURRENT_SOURCE_DIR}/${source} DIRECTORY)
  get_filename_component(source_gen_dir  ${CMAKE_CURRENT_BINARY_DIR}/${source} DIRECTORY)
  add_custom_command(
    DEPENDS
      ${source_src_dir}/${source}
      ${dependencies}
    OUTPUT
      ${source_gen_dir}/${source_filename}.h
      ${source_gen_dir}/${source_filename}.cpp
      ${source_gen_dir}/${source_filename}.interp
      ${source_gen_dir}/${source_filename}.tokens
    COMMAND
      java
    ARGS
      -jar ${CMAKE_SOURCE_DIR}/antlr/antlr-4.7.1-complete.jar
      -Dlanguage=Cpp
      -no-listener
      -no-visitor
      -o ${source_gen_dir}
      ${source_src_dir}/${source}
  )
  set(output ${source_gen_dir}/${source_filename}.cpp)
endfunction()

# Build the ANTLR runtime.
###add_subdirectory(${CMAKE_SOURCE_DIR}/antlr/antlr4-runtime)
include_directories(${CMAKE_SOURCE_DIR}/antlr/antlr4-runtime)

#-------------------------------------------------------------------------------

add_subdirectory(src)
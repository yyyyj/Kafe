cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)

project(Kafe)

# generating the parser
message(STATUS "The grammar ${CMAKE_SOURCE_DIR}/grammar/Kafe.g4 should be now used to generate a new parser")
execute_process(
  COMMAND java -jar antlr/antlr-4.7.1-complete.jar -Dlanguage=Cpp -no-listener -no-visitor -o include/kafe/parser grammar/Kafe.g4
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

message(STATUS "Building project Kafe")

set(INCROOT ${CMAKE_SOURCE_DIR}/include/kafe)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/kafe)

file(GLOB_RECURSE INCLUDE_FILES "${CMAKE_SOURCE_DIR}/tests/*.hpp")
file(GLOB_RECURSE SOURCE_FILES "${SRCROOT}/*.cpp" "${CMAKE_SOURCE_DIR}/tests/*.cpp" "${CMAKE_SOURCE_DIR}/main.cpp")

add_executable(Kafe "${CMAKE_SOURCE_DIR}/main.cpp" ${INCLUDE_FILES} ${SOURCES_FILES})
target_link_libraries(Kafe antlr4_shared)
link_directories(GLOB_RECURSE "${CMAKE_SOURCE_DIR}/dist")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif (MSVC)
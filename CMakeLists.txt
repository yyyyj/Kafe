# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
cmake_policy(SET CMP0015 NEW)
project(Kafe)

if(CMAKE_COMPILER_IS_GNUCC)
  set(CMAKE_CXX_FLAGS "-std=c++14 -fpermissive -O3")
endif()

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
SET (CMAKE_CXX_STANDARD 14)

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4CPP_INCLUDE_DIRS})
link_directories(${ANTLR4CPP_LIBS})
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS}")

file(GLOB_RECURSE INCLUDE_FILES "kafe/*.hpp" "tests/*.hpp")
file(GLOB_RECURSE SRC_FILES "kafe/*.cpp" "tests/tests.cpp" "tests/utils.cpp" "main.cpp")

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(Kafe kafe ${CMAKE_CURRENT_SOURCE_DIR}/Kafe.g)
# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_antlrcpptest})
include_directories("thirdparty/include/")

# add generated grammar to Kafe binary target
add_executable(Kafe main.cpp ${antlr4cpp_src_files_antlrcpptest} ${INCLUDE_FILES} ${SRC_FILE})
add_dependencies(Kafe antlr4cpp antlr4cpp_generation_kafe)
target_link_libraries(Kafe antlr4-runtime)
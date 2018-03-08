cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0015 NEW)

project(Kafe)

message(STATUS "Building project Kafe")

file(GLOB_RECURSE INCLUDE_FILES "${KafeBuilder_SOURCE_DIR}/include/kafe/*.hpp" "${KafeBuilder_SOURCE_DIR}/tests/*.hpp")
file(GLOB_RECURSE SOURCES_FILES "${KafeBuilder_SOURCE_DIR}/include/kafe/parser/*.cpp" "${KafeBuilder_SOURCE_DIR}/src/kafe/*.cpp" "${CMAKE_SOURCE_DIR}/tests/*.cpp")

include_directories(${KafeBuilder_SOURCE_DIR}/include)
include_directories(${KafeBuilder_SOURCE_DIR}/thirdparty)

add_executable(Kafe "${KafeBuilder_SOURCE_DIR}/main.cpp" ${INCLUDE_FILES} ${SOURCES_FILES})

target_link_libraries(Kafe antlr4_shared)

add_custom_command(
    TARGET Kafe POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${KafeBuilder_SOURCE_DIR}/dist/$<CONFIGURATION>" $<TARGET_FILE_DIR:Kafe>
)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Kafe)
set_target_properties(Kafe PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif (MSVC)
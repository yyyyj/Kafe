cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0015 NEW)

project(KafeLib VERSION 1.0.0 DESCRIPTION "Library for using the Kafe open source project")

message(STATUS "Building project KafeLib")

include_directories(${KafeBuilder_SOURCE_DIR}/include)
include_directories(${KafeBuilder_SOURCE_DIR}/thirdparty)

add_library(KafeLib SHARED
    ${KafeBuilder_SOURCE_DIR}/src/kafe/vm/value.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/exception.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/utils.cpp
)

set_target_properties(KafeLib PROPERTIES DEBUG_POSTFIX -d)
set_target_properties(KafeLib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(KafeLib PROPERTIES PUBLIC_HEADER ${KafeBuilder_SOURCE_DIR}/include/kafe/api.hpp)

install(TARGETS KafeLib
    DESTINATION "${CMAKE_HOME_DIRECTORY}/lib/$<CONFIGURATION>"
    PUBLIC_HEADER DESTINATION "${CMAKE_HOME_DIRECTORY}/lib/$<CONFIGURATION>"
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif (MSVC)
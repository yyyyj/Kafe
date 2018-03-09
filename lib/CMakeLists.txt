cmake_minimum_required(VERSION 3.8)
cmake_policy(SET CMP0015 NEW)

project(KafeLib VERSION 1.0.0 DESCRIPTION "Library for using the Kafe open source project")

message(STATUS "Building project ${PROJECT_NAME}")

set(LIB_OUTPUT_DIR "${CMAKE_HOME_DIRECTORY}/lib/$<CONFIGURATION>")

include_directories(${KafeBuilder_SOURCE_DIR}/include)
include_directories(${KafeBuilder_SOURCE_DIR}/thirdparty)

set(lib_kafe_api_SRC
    ${KafeBuilder_SOURCE_DIR}/src/kafe/vm/value.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/exception.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/utils.cpp
)

add_library(${PROJECT_NAME} STATIC ${lib_kafe_api_SRC})

set_target_properties(${PROJECT_NAME}
    PROPERTIES VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        OUTPUT_NAME "kafe-api"
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
        DEBUG_POSTFIX -d
        # PUBLIC_HEADER ${KafeBuilder_SOURCE_DIR}/include/kafe/api.hpp
)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif (MSVC)
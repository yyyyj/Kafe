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
set(lib_kafe_SRC
    ${KafeBuilder_SOURCE_DIR}/src/kafe/utils.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/parser.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/KafeErrorListener.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/kafe.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/exception.cpp
    
    ${KafeBuilder_SOURCE_DIR}/src/kafe/vm/value.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/vm/vm.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/vm/vm_lib.cpp
    
    ${KafeBuilder_SOURCE_DIR}/src/kafe/state/state.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/state/refvar.cpp
    ${KafeBuilder_SOURCE_DIR}/src/kafe/state/native_function.cpp
    
    ${KafeBuilder_SOURCE_DIR}/src/kafe/plugins/loader.cpp
    
    ${KafeBuilder_SOURCE_DIR}/include/kafe/parser/KafeLexer.cpp
    ${KafeBuilder_SOURCE_DIR}/include/kafe/parser/KafeParser.cpp
)

add_library(lib_kafe_api STATIC ${lib_kafe_api_SRC})
add_library(lib_kafe STATIC ${lib_kafe_SRC})

set_target_properties(lib_kafe_api
    PROPERTIES VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        OUTPUT_NAME "kafe-api"
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
        DEBUG_POSTFIX -d
        # PUBLIC_HEADER ${KafeBuilder_SOURCE_DIR}/include/kafe/api.hpp
)
set_target_properties(lib_kafe
    PROPERTIES VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION}
        OUTPUT_NAME "kafe"
        ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
        DEBUG_POSTFIX -d
)

install(TARGETS lib_kafe_api
    ARCHIVE DESTINATION lib
)
install(TARGETS lib_kafe
    ARCHIVE DESTINATION lib
)

set_property(TARGET lib_kafe_api PROPERTY CXX_STANDARD 17)
set_property(TARGET lib_kafe_api PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lib_kafe_api PROPERTY CXX_EXTENSIONS OFF)

set_property(TARGET lib_kafe PROPERTY CXX_STANDARD 17)
set_property(TARGET lib_kafe PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET lib_kafe PROPERTY CXX_EXTENSIONS OFF)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
endif (MSVC)
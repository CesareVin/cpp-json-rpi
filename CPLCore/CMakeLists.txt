cmake_minimum_required(VERSION 2.8.4)
project(CPLCore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

set(SOURCE_FILES
    src/BaseCommand.cpp
    src/BaseCommand.h
    src/DeviceBase.h
    src/NodeBase.cpp
    src/NodeBase.h
    src/Server.cpp
    src/Server.h)
    
include_directories(.)
include_directories(${PISTACHE_INCLUDE})
include_directories(${RAPID_JSON_INCLUDE})
link_directories(${PISTACHE_LIB_PATH})

add_library(CPLCore ${SOURCE_FILES})

target_link_libraries(CPLCore net_static pthread)
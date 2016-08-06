cmake_minimum_required(VERSION 2.8.4)
project(CPLCore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/BaseCommand.cpp
    src/BaseCommand.h
    src/DeviceBase.h
    src/NodeBase.cpp
    src/NodeBase.h
    src/Server.cpp
    src/Server.h)


include_directories(${CPPREST_INCLUDE})
link_directories(${CPPREST_LIB_PATH})

add_library(CPLCore ${SOURCE_FILES})

target_link_libraries(CPLCore boost_system crypto ssl cpprest)
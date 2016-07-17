cmake_minimum_required(VERSION 2.8.4)
project(CPLCore)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/BaseCommand.cpp
    src/BaseCommand.h
    src/ICommand.h
    src/IDevice.h
    src/NodeBase.cpp
    src/NodeBase.h)

add_library(CPLCore ${SOURCE_FILES})
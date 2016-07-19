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

set(CPPREST_INCLUDE /opt/cpprestsdk/Release/include)
set(CPPREST_LIB_PATH /opt/cpprestsdk/Release/build.debug/Binaries)
include_directories(${CPPREST_INCLUDE})
link_directories(${CPPREST_LIB_PATH})

add_library(CPLCore ${SOURCE_FILES})

target_link_libraries(CPLCore boost_system crypto ssl cpprest)
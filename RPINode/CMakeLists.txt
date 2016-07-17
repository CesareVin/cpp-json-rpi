cmake_minimum_required(VERSION 2.8.4)
project(RPINode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/common.h
    src/main.cpp
    src/MotorDevice.cpp
    src/MotorDevice.h
    src/RPINode.cpp
    src/RPINode.h
    src/Server.cpp
    src/Server.h)

set(CPPREST_INCLUDE
    /opt/cpprestsdk/Release/include)
set(CPLCORE_INCLUDE
    /home/cesare/Project/jarvis/CPLCore/src)
set(CPPREST_LIB_PATH
    /opt/cpprestsdk/Release/build.debug/Binaries)
set(CPLCORE_LIB_PATH
    /home/cesare/Desktop)

include_directories(.)
include_directories(src)
include_directories(${CPPREST_INCLUDE})
include_directories(${CPLCORE_INCLUDE})

link_directories(${CPPREST_LIB_PATH})
link_directories(${CPLCORE_LIB_PATH})

add_executable(RPINode ${SOURCE_FILES})

target_link_libraries(RPINode CPLCore boost_system crypto ssl cpprest)
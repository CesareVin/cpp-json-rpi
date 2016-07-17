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

include_directories(.)
include_directories(src)
include_directories(/opt/cpprestsdk/Release/include)
include_directories(/home/cesare/Project/jarvis/CPLCore/src)

link_directories(/opt/cpprestsdk/Release/build.debug/Binaries)
link_directories(/home/cesare/Desktop)

add_executable(RPINode ${SOURCE_FILES})

target_link_libraries(RPINode CPLCore boost_system crypto ssl cpprest)
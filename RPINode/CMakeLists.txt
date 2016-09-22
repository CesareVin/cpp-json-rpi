cmake_minimum_required(VERSION 2.8.4)
project(RPINode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
    src/MotorDevice.cpp
    src/MotorDevice.h
    src/CameraDevice.cpp
    src/CameraDevice.h
    src/RPINode.cpp
    src/RPINode.h)


# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

include_directories(.)
include_directories(src)

include_directories(${CPLCORE_INCLUDE})
include_directories(${PISTACHE_INCLUDE})
include_directories(${RAPID_JSON_INCLUDE})

link_directories(${PISTACHE_LIB_PATH})
link_directories(${CPLCORE_LIB_PATH})

add_executable(RPINode ${SOURCE_FILES})

target_link_libraries(RPINode CPLCore net_static pthread)
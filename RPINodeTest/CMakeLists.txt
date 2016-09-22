cmake_minimum_required(VERSION 2.8.4)

project(RPICoreTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/RPINodeTest.cpp
        src/RPINodeFixture.cpp)


# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

include_directories(.)
include_directories(../RPINode)
include_directories(${GTEST_INCLUDE})
include_directories(${CPLCORE_INCLUDE})

link_directories(${GTEST_LIB_PATH})
link_directories(${CPLCORE_LIB_PATH})

add_executable(RPINodeTest ${SOURCE_FILES})

target_link_libraries(RPINodeTest CPLCore gtest_main gtest pthread )
cmake_minimum_required(VERSION 2.8.4)
project(CPLCoreTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/BaseCommandFixture.cpp
    src/BaseCommandTest.cpp
    src/CPLCoreTest.cpp
    src/NodeTest.cpp
    src/NoteFixture.cpp)

include_directories(.)
include_directories(src)
include_directories(/opt/googletest/googletest/include)
include_directories(/home/cesare/Project/jarvis/CPLCore/src)

link_directories(/opt/googletest/googletest)
link_directories(/home/cesare/Desktop)

add_executable(CPLCoreTest ${SOURCE_FILES})

target_link_libraries(CPLCoreTest CPLCore gtest_main gtest pthread )
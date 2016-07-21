cmake_minimum_required(VERSION 2.8.4)
project(CPLCoreTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/CPLCoreTest.cpp
    src/BaseCommandTest.cpp
    src/BaseCommandFixture.cpp)

set(CPPREST_INCLUDE /opt/cpprestsdk/Release/include)
set(CPPREST_LIB_PATH /opt/cpprestsdk/Release/build.debug/Binaries)
include_directories(${CPPREST_INCLUDE})


include_directories(.)
include_directories(src)
include_directories(/opt/googletest/googletest/include)
include_directories(${CPPREST_INCLUDE})
include_directories(/home/cesare/Project/jarvis/CPLCore/src)

link_directories(/opt/googletest/googletest)
link_directories(/home/cesare/Desktop)
link_directories(${CPPREST_LIB_PATH})

add_executable(CPLCoreTest ${SOURCE_FILES})

target_link_libraries(CPLCoreTest CPLCore boost_system crypto ssl cpprest gtest_main gtest pthread )
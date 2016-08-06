cmake_minimum_required(VERSION 2.8.4)
project(CPLCoreTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/CPLCoreTest.cpp
    src/BaseCommandTest.cpp
    src/BaseCommandFixture.cpp)


include_directories(${CPPREST_INCLUDE})


include_directories(.)
include_directories(src)
include_directories(${GTEST_INCLUDE})
include_directories(${CPPREST_INCLUDE})
include_directories(${CPLCORE_INCLUDE})

link_directories(${GTEST_LIB_PATH})
link_directories(${CPLCORE_LIB_PATH})
link_directories(${CPPREST_LIB_PATH})

add_executable(CPLCoreTest ${SOURCE_FILES})

target_link_libraries(CPLCoreTest CPLCore boost_system crypto ssl cpprest gtest_main gtest pthread )
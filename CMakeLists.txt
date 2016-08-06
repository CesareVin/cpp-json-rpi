cmake_minimum_required(VERSION 2.8.4)
project(jarvis)

set(GTEST_INCLUDE /opt/googletest/googletest/include)
set(CPPREST_INCLUDE /opt/cpprestsdk/Release/include)
set(CPLCORE_INCLUDE /home/cesare/Project/jarvis/CPLCore/src)
set(CPPREST_LIB_PATH /opt/cpprestsdk/Release/build.debug/Binaries)
set(CPLCORE_LIB_PATH /home/cesare/Project/jarvis/build/CPLCore)
SET(GTEST_LIB_PATH /opt/googletest/googletest)

subdirs(CPLCore CPLCoreTest RPINode)

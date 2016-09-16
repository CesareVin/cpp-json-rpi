cmake_minimum_required(VERSION 2.8.4)
project(jarvis)

set(GTEST_INCLUDE /opt/googletest/googletest/include)
set(CPLCORE_INCLUDE /home/cesare/Project/jarvis/CPLCore/src)
set(PISTACHE_INCLUDE /usr/local/include/pistache)
set(RAPID_JSON_INCLUDE /opt/rapidjson/include)

set(CPLCORE_LIB_PATH /home/cesare/Project/jarvis/build/CPLCore)
SET(GTEST_LIB_PATH /opt/googletest/googletest)
set(PISTACHE_LIB_PATH /opt/pistache/build/src)

subdirs(CPLCore CPLCoreTest RPINode)



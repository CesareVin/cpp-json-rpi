project(jarvis)

set(GTEST_INCLUDE /opt/googletest/googletest/include)
set(CPPREST_INCLUDE /opt/cpprestsdk/Release/include)
set(CPLCORE_INCLUDE /home/cesare/Project/jarvis/CPLCore/src)
set(CPPREST_LIB_PATH /opt/cpprestsdk/Release/build.debug/Binaries)
set(CPLCORE_LIB_PATH /home/cesare/Desktop)
SET(GTEST_LIB_PATH /opt/googletest/googletest)

subdirs(CPLCore CPLCoreTest RPINode)

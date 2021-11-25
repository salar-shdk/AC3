cmake_minimum_required(VERSION 3.22)
project(ac3-src)

set(HEADER_LIST AC3.h)

set(SOURCE_LIST AC3.cpp)

set(TEST_SOURCE_LIST main.cpp)

add_library(ac3 SHARED ${SOURCE_LIST})

add_executable(ac3-test ${TEST_SOURCE_LIST})
target_link_libraries(ac3-test ac3)
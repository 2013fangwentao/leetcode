cmake_minimum_required(VERSION 2.8)
project(leetcode)

set(CMAKE_BUILD_TYPE debug)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_definitions(-std=c++11)
add_executable(${PROJECT_NAME} ./38.报数.cpp)
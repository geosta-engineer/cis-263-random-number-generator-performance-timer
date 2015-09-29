cmake_minimum_required(VERSION 3.3)
project(hw28)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp hw28.cpp)
add_executable(hw28 ${SOURCE_FILES} hw28.cpp)
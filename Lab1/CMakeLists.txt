cmake_minimum_required(VERSION 3.8)
project(Lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Functions.h Functions.cpp)
add_executable(Lab1 ${SOURCE_FILES})
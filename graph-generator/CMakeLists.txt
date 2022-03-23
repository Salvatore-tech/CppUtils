cmake_minimum_required(VERSION 3.21)
project(graph-generator)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES src/main.cpp)
add_executable(graph-generator ${SOURCE_FILES})

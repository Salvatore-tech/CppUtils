cmake_minimum_required(VERSION 3.21)
project(graphnode)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/GraphNode.cpp include/GraphNode.h)
add_library(graphnode ${SOURCE_FILES})

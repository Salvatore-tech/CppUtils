cmake_minimum_required(VERSION 3.21)
project(graphnode)
set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES include/GraphNode.h)
set(SOURCE_FILES src/GraphNode.cpp)
add_library(graphnode ${HEADER_FILES} ${SOURCE_FILES})

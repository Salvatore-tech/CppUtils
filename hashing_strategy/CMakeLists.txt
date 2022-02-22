cmake_minimum_required(VERSION 3.21)
project(hashing_strategy)
set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES include/HashingStrategy.h include/LinearProbingStrategy.h include/DoubleHashingStrategy.h)
set(SOURCE_FILES src/LinearProbingStrategy.cpp src/DoubleHashingStrategy.cpp)
add_library(hashing_strategy ${HEADER_FILES} ${SOURCE_FILES})
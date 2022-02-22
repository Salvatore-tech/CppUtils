cmake_minimum_required(VERSION 3.21)
project(iograph)

set(CMAKE_CXX_STANDARD 20)
set(HEADER_FILES include/FileMetadata.h include/InputOutputHandler.h)
set(SOURCE_FILES src/InputOutputHandler.cpp)
add_library(iograph ${HEADER_FILES} ${SOURCE_FILES})

cmake_minimum_required(VERSION 3.16)
project(Pointers)

set(CMAKE_CXX_STANDARD 14)


add_executable(Pointers main.cpp scoped_ptr.h tests_scoped_ptr.h shared_ptr.h tests_shared_ptr.h)
#set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR})
#set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR})

#file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
#file(GLOB_RECURSE HEADERS ${PROJECT_SOURCES_DIR}/*.cpp)

#add_executable(Pointers ${HEADERS} ${SOURCES})

#include_directories(${PROJECT_HEADERS_DIR})
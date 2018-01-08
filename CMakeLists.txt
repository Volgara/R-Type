cmake_minimum_required(VERSION 3.8)
project(RType)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp server/Socket.cpp server/Socket.hpp)
add_executable(RType ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.28)
project(main)

set(CMAKE_CXX_STANDARD 26)

add_executable(main main.cpp
        approx.cpp
        debug.h
        debug.h)

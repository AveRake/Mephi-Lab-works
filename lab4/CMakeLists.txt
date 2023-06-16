cmake_minimum_required(VERSION 3.24)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 main.cpp detours.h)
add_executable(lab4test test.cpp detours.h)
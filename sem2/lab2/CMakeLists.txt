cmake_minimum_required(VERSION 3.24)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp class.h)
add_executable(lab2_test test.cpp class.h)
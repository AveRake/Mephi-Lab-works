cmake_minimum_required(VERSION 3.24)
project(Sem3Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sem3Lab1 main.cpp smartPointer.h sequence.h)
add_executable(Sem3Lab1Testing testing.cpp smartPointer.h sequence.h)
add_executable(Sem3Lab1Benchmark benchmark.cpp smartPointer.h)
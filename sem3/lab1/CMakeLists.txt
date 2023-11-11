cmake_minimum_required(VERSION 3.24)
project(Sem3Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sem3Lab1 main.cpp SmartPointer.h Sequence.h Benchmark.h)
add_executable(Sem3Lab1Testing testing.cpp SmartPointer.h Sequence.h)

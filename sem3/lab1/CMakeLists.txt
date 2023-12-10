cmake_minimum_required(VERSION 3.24)
project(Sem3Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sem3Lab1 mainPart/main.cpp mainPart/smartPointer.h mainPart/sequence.h)
add_executable(Sem3Lab1Testing mainPart/smartPointer.h mainPart/sequence.h tests/startTests.cpp tests/smartPointerTesting.h)
add_executable(Sem3Lab1Benchmark startBenchmark/benchmark.cpp mainPart/smartPointer.h)
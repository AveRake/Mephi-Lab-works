cmake_minimum_required(VERSION 3.24)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 mainPart/main.cpp mainPart/smartPointers.h mainPart/sequence.h mainPart/sorting.h)
add_executable(lab2Testing tests/startTests.cpp tests/sequencesTesting.cpp tests/sequencesTesting.h tests/sortingMethodsTesting.cpp tests/sortingMethodsTesting.h mainPart/smartPointers.h mainPart/sequence.h mainPart/sorting.h)
add_executable(lab2Benchmark SortsBenchmark/benchmark.cpp mainPart/smartPointers.h mainPart/sequence.h mainPart/sorting.h)
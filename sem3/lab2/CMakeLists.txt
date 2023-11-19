cmake_minimum_required(VERSION 3.24)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 mainPart/main.cpp mainPart/SmartPointers.h mainPart/Sequence.h mainPart/Sorting.h)
add_executable(lab2Testing tests/startTests.cpp tests/SequencesTesting.cpp tests/SequencesTesting.h tests/SortingMethodsTesting.cpp tests/SortingMethodsTesting.h mainPart/SmartPointers.h mainPart/Sequence.h mainPart/Sorting.h)

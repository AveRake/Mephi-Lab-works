cmake_minimum_required(VERSION 3.24)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 UI/UI.cpp "forHistogram/histogram .h" sequence/person.h forHistogram/myMap.h sequence/smartPointer.h sequence/sequences.h)

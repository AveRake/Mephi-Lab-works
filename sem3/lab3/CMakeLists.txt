cmake_minimum_required(VERSION 3.24)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 UI/UI.cpp "forHistogram/histogram .h" forHistogram/myMap.h taskCache/cache.h taskCache/unorderedMap.h)
add_executable(lab3Test tests/test.cpp "forHistogram/histogram .h" forHistogram/myMap.h taskCache/cache.h taskCache/unorderedMap.h tests/unorderedMaptests.h tests/cacheTests.h tests/myMapTest.h tests/histogramTest.h)

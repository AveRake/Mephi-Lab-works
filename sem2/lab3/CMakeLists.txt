cmake_minimum_required(VERSION 3.24)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3 main.cpp class.h SquareMatrix.h RectangularMatrix.h Stack.h)
add_executable(lab3test classTest.cpp class.h SquareMatrix.h RectangularMatrix.h Stack.h)

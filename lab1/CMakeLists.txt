cmake_minimum_required(VERSION 3.24)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c constMultiply.c addMatrix.c multiply.c linearly.c)
add_executable(lab1_test run_test.c constMultiply.c constMultiplyTest.c addMatrix.c addMatrixTest.c multiply.c multiplyTest.c linearlyTest.c linearly.c)

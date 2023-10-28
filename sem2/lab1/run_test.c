#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "constMultiplyTest.h"
#include "addMatrixTest.h"
#include "multiplyTest.h"
#include "linearlyTest.h"

int main() {
    constMultiplyTest();
    addMatrixTest();
    multiplyTest();
    linearlyTest();
    printf("All 17 tests have been checked!\n");
    printf("Press any button to end the program\n");
    _getch();
    return 0;
}

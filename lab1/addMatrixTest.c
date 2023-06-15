#include <stdio.h>
#include <stdlib.h>
#include "addMatrix.h"

void addMatrixTest() {
    void* mas = 0;
    void* matrix = 0;
    int type = 1;
    int value = 1;
    int height = 2;
    int width = 2;
    int result = 1;

    //Test 1

    mas = (int*)malloc(height * width * sizeof(int));
    matrix = (int*)malloc(height * width * sizeof(int));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value++;
        }
    value = 1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)matrix)[j * width + i] = value;
            value++;
        }
    value = 1;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((int*)mas)[j * width + i] != value * 2) {
                result = 0;
            }
            value++;
        }
    value = 1;

    if (result == 1)
        printf("The first test with matrix addition passed!\n");
    if (result == 0)
        printf("The first matrix addition test failed!\n");

    free(mas);
    free(matrix);

    //Test 2

    result = 1;
    mas = (int*)malloc(height * width * sizeof(int));
    matrix = (int*)malloc(height * width * sizeof(int));
    value = 2;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value *= 2;
        }
    value = 2;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)matrix)[j * width + i] = value;
            value *= 2;
        }
    value = 2;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((int*)mas)[j * width + i] != value * 2) {
                result = 0;
            }
            value *= 2;
        }
    value = 2;

    if (result == 1)
        printf("The second test with matrix addition passed!\n");
    if (result == 0)
        printf("The second matrix addition test failed!\n");

    free(mas);
    free(matrix);

    //Test 3

    result = 1;
    type = 2;
    mas = (float*)malloc(height * width * sizeof(float));
    matrix = (float*)malloc(height * width * sizeof(float));
    float float_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value += float_value ;
        }
    float_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)matrix)[j * width + i] = float_value;
            float_value += float_value;
        }
    float_value = 1.1;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((float*)mas)[j * width + i] != float_value * 2.0) {
                result = 0;
            }
            float_value += float_value;
        }
    float_value = 1.1;

    if (result == 1)
        printf("The third test with matrix addition passed!\n");
    if (result == 0)
        printf("The third matrix addition test failed!\n");

    free(mas);
    free(matrix);

    //Test 4

    result = 1;
    type = 2;
    mas = (float*)malloc(height * width * sizeof(float));
    matrix = (float*)malloc(height * width * sizeof(float));
    float_value = 2.15;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value *= 3.0 ;
        }
    float_value = 2.15;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)matrix)[j * width + i] = float_value;
            float_value *= 3.0;
        }
    float_value = 2.15;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((float*)mas)[j * width + i] != float_value * 2.0) {
                result = 0;
            }
            float_value *= 3.0;
        }
    float_value = 2.15;

    if (result == 1)
        printf("The fourth test with matrix addition passed!\n");
    if (result == 0)
        printf("The fourth matrix addition test failed!\n");

    free(mas);
    free(matrix);

    //Test 5

    result = 1;
    type = 3;
    mas = (double*)malloc(height * width * sizeof(double));
    matrix = (double*)malloc(height * width * sizeof(double));
    double double_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value += double_value ;
        }
    double_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)matrix)[j * width + i] = double_value;
            double_value += double_value;
        }
    double_value = 1.1;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((double*)mas)[j * width + i] != double_value * 2.0) {
                result = 0;
            }
            double_value += double_value;
        }
    double_value = 1.1;

    if (result == 1)
        printf("The fifth test with matrix addition passed!\n");
    if (result == 0)
        printf("The fifth matrix addition test failed!\n");

    free(mas);
    free(matrix);

    //Test 6

    result = 1;
    type = 3;
    mas = (double*)malloc(height * width * sizeof(double));
    matrix = (double*)malloc(height * width * sizeof(double));
    double_value = 2.15;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value *= 3.0 ;
        }
    double_value = 2.15;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)matrix)[j * width + i] = double_value;
            double_value *= 3.0;
        }
    double_value = 2.15;

    addMatrix((void **) &mas, &height, &width, &type, (void **) &matrix);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((double*)mas)[j * width + i] != double_value * 2.0) {
                result = 0;
            }
            double_value *= 3.0;
        }
    double_value = 2.15;

    if (result == 1)
        printf("The sixth test with matrix addition passed!\n");
    if (result == 0)
        printf("The sixth matrix addition test failed!\n");

    free(mas);
    free(matrix);
    printf("\n");
}



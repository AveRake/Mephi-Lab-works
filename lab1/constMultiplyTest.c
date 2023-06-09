#include <stdio.h>
#include <stdlib.h>
#include "constMultiply.h"

void constMultiplyTest() {
    //Test 1
    int result = 1;
    int type = 1;
    int height = 3;
    int width = 3;
    int scalar = 5;
    int value = 1;
    void* mas = 0;
    mas = (int*)malloc(height * width * sizeof(int));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value++;
        }

    value = 1;
    constMultiply(&mas, &height, &width, (void**) &scalar, &type);

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            if (((int*)mas)[j * width + i] != value * scalar)
                result = 0;
            value++;
        }

    if (result == 1)
        printf("The first test with matrix multiply by a const passed!\n");
    if (result == 0)
        printf("The first matrix test multiply by a const failed!\n");

    free(mas);

    //Test 2

    result = 1;
    double c;
    double d;
    type = 3;
    void* massive = 0;
    massive = (double*)malloc(height * width * sizeof(double));
    double double_value = 1.1;
    double double_scalar = 5.56;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)massive)[j * width + i] = double_value;
            double_value += double_value;
        }

    constMultiply(&massive, &height, &width, (void **) &double_scalar, &type);

    double_value = 1.1;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            c = ((double*)massive)[j * width + i];
            d = (double_value * double_scalar);
            if (c != d)
                result = 0;
            double_value += double_value;
        }
    }


    if (result == 1)
        printf("The second test with matrix multiply by a const passed!\n");
    if (result == 0)
        printf("The second matrix test multiply by a const failed!\n");

    free(massive);

    //Test 3

    result = 1;
    massive = (double*)malloc(height * width * sizeof(double));
    double_value = 2.1;
    double_scalar = 2.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)massive)[j * width + i] = double_value;
            double_value *= 2.0;
        }

    constMultiply(&massive, &height, &width, (void **) &double_scalar, &type);

    double_value = 2.1;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            c = ((double*)massive)[j * width + i];
            d = (double_value * double_scalar);
            if (c != d)
                result = 0;
            double_value *= 2.0;
        }
    }

    if (result == 1)
        printf("The third test with matrix multiply by a const passed!\n");
    if (result == 0)
        printf("The third matrix test multiply by a const failed!\n");

    free(massive);

    //Test 4

    result = 1;
    float a;
    float b;
    type = 2;
    massive = (float*)malloc(height * width * sizeof(float));
    float float_value = 5.1;
    float float_scalar = 5.6;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)massive)[j * width + i] = float_value;
            float_value *= 2.0;
        }

    constMultiply(&massive, &height, &width, (void **) &float_scalar, &type);

    float_value = 5.1;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            a = ((float*)massive)[j * width + i];
            b = (float_value * float_scalar);
            if (a != b)
                result = 0;
            float_value *= 2.0;
        }
    }


    if (result == 1)
        printf("The fourth test with matrix multiply by a const passed!\n");
    if (result == 0)
        printf("The fourth matrix test multiply by a const failed!\n");

    free(massive);

    //Test 5

    result = 1;
    massive = (float*)malloc(height * width * sizeof(float));
    float_value = 7.9;
    float_scalar = 8.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)massive)[j * width + i] = float_value;
            float_value *= 1.5;
        }

    constMultiply(&massive, &height, &width, (void **) &float_scalar, &type);

    float_value = 7.9;
    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {
            a = ((float*)massive)[j * width + i];
            b = float_value * float_scalar;
            if (a != b)
                result = 0;
            float_value *= 1.5;
        }
    }

    if (result == 1)
        printf("The fifth test with matrix multiply by a const passed!\n");
    if (result == 0)
        printf("The fifth matrix test multiply by a const failed!\n");

    free(massive);
    printf("\n");
}

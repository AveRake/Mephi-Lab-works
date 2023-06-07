#include <stdio.h>
#include <stdlib.h>
#include "multiply.h"
#include "multiplyTest.h"

void multiplyTest() {
    void* mas = 0;
    void* matrix = 0;
    int result = 1;
    int type = 1;
    int height = 2;
    int width = 2;
    int value = 1;

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

    multiply(&mas, &height, &width, &type, &matrix);

    if (((int*)mas)[0] != 7)
        result = 0;
    if (((int*)mas)[1] != 10)
        result = 0;
    if (((int*)mas)[2] != 15)
        result = 0;
    if (((int*)mas)[3] != 22)
        result = 0;

    if (result == 1)
        printf("The first test with matrix multiply passed!\n");
    if (result == 0)
        printf("The first matrix multiply test failed!\n");

    free(mas);
    free(matrix);

    //Test 2

    result = 1;
    value = 2;
    height = 3;
    width = 3;
    mas = (int*)malloc(height * width * sizeof(int));
    matrix = (int*)malloc(height * width * sizeof(int));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value *= 2;
        }
    value = 1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)matrix)[j * width + i] = value;
            value++;
        }

    multiply(&mas, &height, &width, &type, &matrix);

    if (((int*)mas)[0] != 74)
        result = 0;
    if (((int*)mas)[1] != 88)
        result = 0;
    if (((int*)mas)[2] != 102)
        result = 0;
    if (((int*)mas)[3] != 592)
        result = 0;
    if (((int*)mas)[4] != 704)
        result = 0;
    if (((int*)mas)[5] != 816)
        result = 0;
    if (((int*)mas)[6] != 4736)
        result = 0;
    if (((int*)mas)[7] != 5632)
        result = 0;
    if (((int*)mas)[8] != 6528)
        result = 0;

    if (result == 1)
        printf("The second test with matrix multiply passed!\n");
    if (result == 0)
        printf("The second matrix multiply test failed!\n");

    free(mas);
    free(matrix);

    //Test 3

    result = 1;
    type = 2;
    height = 2;
    width = 2;
    float float_value = 1.1;
    mas = (float*)malloc(height * width * sizeof(float));
    matrix = (float*)malloc(height * width * sizeof(float));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value++;
        }
    float_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)matrix)[j * width + i] = float_value;
            float_value++;
        }

    multiply(&mas, &height, &width, &type, &matrix);

    if ((int)((float*)mas)[0] != (int)7.72)
        result = 0;
    if ((int)((float*)mas)[1] != (int)10.92)
        result = 0;
    if ((int)((float*)mas)[2] != (int)16.12)
        result = 0;
    if ((int)((float*)mas)[3] != (int)23.32)
        result = 0;

    if (result == 1)
        printf("The third test with matrix multiply passed!\n");
    if (result == 0)
        printf("The third matrix multiply test failed!\n");

    free(mas);
    free(matrix);

    //Test 4

    result = 1;
    type = 2;
    height = 2;
    width = 2;
    float_value = 1.1;
    mas = (float*)malloc(height * width * sizeof(float));
    matrix = (float*)malloc(height * width * sizeof(float));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value += float_value;
        }
    float_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)matrix)[j * width + i] = float_value;
            float_value++;
        }

    multiply(&mas, &height, &width, &type, &matrix);

    if ((int)((float*)mas)[0] != (int)8.03)
        result = 0;
    if ((int)((float*)mas)[1] != (int)11.33)
        result = 0;
    if ((int)((float*)mas)[2] != (int)32.12)
        result = 0;
    if ((int)((float*)mas)[3] != (int)45.32)
        result = 0;

    if (result == 1)
        printf("The fourth test with matrix multiply passed!\n");
    if (result == 0)
        printf("The fourth matrix multiply test failed!\n");

    free(mas);
    free(matrix);

    //Test 5

    result = 1;
    type = 3;
    height = 2;
    width = 2;
    double double_value = 1.1;
    mas = (double*)malloc(height * width * sizeof(double));
    matrix = (double*)malloc(height * width * sizeof(double));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value++;
        }
    double_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)matrix)[j * width + i] = double_value;
            double_value++;
        }

    multiply(&mas, &height, &width, &type, &matrix);

    if ((int)((double*)mas)[0] != (int)7.72)
        result = 0;
    if ((int)((double*)mas)[1] != (int)10.92)
        result = 0;
    if ((int)((double*)mas)[2] != (int)16.12)
        result = 0;
    if ((int)((double*)mas)[3] != (int)23.32)
        result = 0;

    if (result == 1)
        printf("The fifth test with matrix multiply passed!\n");
    if (result == 0)
        printf("The fifth matrix multiply test failed!\n");

    free(mas);
    free(matrix);

    //Test 6

    result = 1;
    type = 3;
    height = 2;
    width = 2;
    double_value = 1.1;
    mas = (double*)malloc(height * width * sizeof(double));
    matrix = (double*)malloc(height * width * sizeof(double));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value += double_value;
        }
    double_value = 1.1;

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)matrix)[j * width + i] = double_value;
            double_value++;
        }

    multiply(&mas, &height, &width, &type, &matrix);

    if ((int)((double*)mas)[0] != (int)8.03)
        result = 0;
    if ((int)((double*)mas)[1] != (int)11.33)
        result = 0;
    if ((int)((double*)mas)[2] != (int)32.12)
        result = 0;
    if ((int)((double*)mas)[3] != (int)45.32)
        result = 0;

    if (result == 1)
        printf("The sixth test with matrix multiply passed!\n");
    if (result == 0)
        printf("The sixth matrix multiply test failed!\n");

    free(mas);
    free(matrix);
    printf("\n");
}
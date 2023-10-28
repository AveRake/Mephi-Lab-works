#include <stdio.h>
#include <stdlib.h>
#include "linearly.h"

void linearlyTest() {
    int result = 1;
    int type = 1;
    void* mas = 0;
    int height = 2;
    int width = 2;
    int value = 1;
    int fc = 1;
    int sc = 2;
    int tc = 0;

    //Test 1

    mas = (int*)malloc(height * width * sizeof(int));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value++;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &sc, &tc);

    if (((int*)mas)[0] != 7)
        result = 0;
    if (((int*)mas)[1] != 10)
        result = 0;
    if (((int*)mas)[2] != 3)
        result = 0;
    if (((int*)mas)[3] != 4)
        result = 0;

    if (result == 1)
        printf("The first test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The first matrix linear operations test failed!\n");

    free(mas);

    //Test 2

    result = 1;
    fc = 0;
    sc = 5;
    tc = 1;
    value = 2;
    mas = (int*)malloc(height * width * sizeof(int));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((int*)mas)[j * width + i] = value;
            value *= 2;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &sc, &tc);

    if (((int*)mas)[0] != 2)
        result = 0;
    if (((int*)mas)[1] != 4)
        result = 0;
    if (((int*)mas)[2] != 18)
        result = 0;
    if (((int*)mas)[3] != 36)
        result = 0;

    if (result == 1)
        printf("The second test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The second matrix linear operations test failed!\n");

    free(mas);

    //Test 3

    result = 1;
    fc = 0;
    float float_sc = 2.0;
    tc = 1;
    type = 2;
    float float_value = 1.1;
    mas = (float*)malloc(height * width * sizeof(float));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value++;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &float_sc, &tc);

    if ((int)((float*)mas)[0] != (int)1.1)
        result = 0;
    if ((int)((float*)mas)[1] != (int)2.1)
        result = 0;
    if ((int)((float*)mas)[2] != (int)5.3)
        result = 0;
    if ((int)((float*)mas)[3] != (int)8.3)
        result = 0;

    if (result == 1)
        printf("The third test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The third matrix linear operations test failed!\n");

    free(mas);

    //Test 4

    result = 1;
    fc = 1;
    float_sc = 5.1;
    tc = 0;
    type = 2;
    float_value = 1.2;
    mas = (float*)malloc(height * width * sizeof(float));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((float*)mas)[j * width + i] = float_value;
            float_value++;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &float_sc, &tc);

    if ((int)((float*)mas)[0] != (int)17.52)
        result = 0;
    if ((int)((float*)mas)[1] != (int)23.62)
        result = 0;
    if ((int)((float*)mas)[2] != (int)3.2)
        result = 0;
    if ((int)((float*)mas)[3] != (int)4.2)
        result = 0;

    if (result == 1)
        printf("The fourth test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The fourth matrix linear operations test failed!\n");

    free(mas);

    //Test 5

    result = 1;
    fc = 0;
    double double_sc = 2.0;
    tc = 1;
    type = 3;
    double double_value = 1.1;
    mas = (double*)malloc(height * width * sizeof(double));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value++;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &double_sc, &tc);

    if ((int)((double*)mas)[0] != (int)1.1)
        result = 0;
    if ((int)((double*)mas)[1] != (int)2.1)
        result = 0;
    if ((int)((double*)mas)[2] != (int)5.3)
        result = 0;
    if ((int)((double*)mas)[3] != (int)8.3)
        result = 0;

    if (result == 1)
        printf("The fifth test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The fifth matrix linear operations test failed!\n");

    free(mas);

    //Test 4

    result = 1;
    fc = 1;
    double_sc = 5.1;
    tc = 0;
    double_value = 1.2;
    mas = (double*)malloc(height * width * sizeof(double));

    for(int j = 0; j < height; j++)
        for(int i = 0; i < width; i++) {
            ((double*)mas)[j * width + i] = double_value;
            double_value++;
        }

    linearly(&mas, &height, &width, &type, &fc, (void **) &double_sc, &tc);

    if ((int)((double*)mas)[0] != (int)17.52)
        result = 0;
    if ((int)((double*)mas)[1] != (int)23.62)
        result = 0;
    if ((int)((double*)mas)[2] != (int)3.2)
        result = 0;
    if ((int)((double*)mas)[3] != (int)4.2)
        result = 0;

    if (result == 1)
        printf("The sixth test with matrix linear operations passed!\n");
    if (result == 0)
        printf("The sixth matrix linear operations test failed!\n");

    free(mas);
    printf("\n");
}

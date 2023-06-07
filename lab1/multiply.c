#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


void multiply(void** mas, int* height, int* width, int* type, void** matrix) {
    void *getMatrix = 0;
    if (*type == 1)
        getMatrix = (int*)calloc(*width * *height, sizeof(int));
    if (*type == 2)
        getMatrix = (float*)calloc(*width * *height, sizeof(float));
    if (*type == 3)
        getMatrix = (double*)calloc(*width * *height, sizeof(double));

    for(int j = 0; j < *height; j++)
        for(int i = 0; i < *width; i++)
            for(int v = 0; v < *height; v++) {
                if (*type == 1)
                    ((int*)getMatrix)[j * *width + i] += ((int*)(*mas))[j * *width + v] * ((int*)*matrix)[v * *width + i];
                if (*type == 2)
                    ((float*)getMatrix)[j * *width + i] += ((float*)(*mas))[j * *width + v] * ((float*)*matrix)[v * *width + i];
                if (*type == 3)
                    ((double*)getMatrix)[j * *width + i] += ((double*)(*mas))[j * *width + v] * ((double*)*matrix)[v * *width + i];
            }

    free(*mas);

    if (*type == 1)
        *mas = (int*)calloc(*width * *height, sizeof(int));
    if (*type == 2)
        *mas = (float*)calloc(*width * *height, sizeof(float));
    if (*type == 3)
        *mas = (double*)calloc(*width * *height, sizeof(double));

    for (int j = 0; j < *height; j++)
        for (int i = 0; i < *width; i++) {
            if (*type == 1)
                ((int*)(*mas))[j * *width + i] = ((int*)getMatrix)[j * *width + i];
            if (*type == 2)
                ((float*)(*mas))[j * *width + i] = ((float*)getMatrix)[j * *width + i];
            if (*type == 3)
                ((double*)(*mas))[j * *width + i] = ((double*)getMatrix)[j * *width + i];
        }

    free(getMatrix);
}
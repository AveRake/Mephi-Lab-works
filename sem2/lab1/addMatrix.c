#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


void addMatrix(void** mas, int* height, int* width, int* type, void** matrix) {
    for(int j = 0; j < *height; j++)
        for(int i = 0; i < *width; i++) {
            if (*type == 1) {
                ((int*)(*mas))[j * *width + i] += ((int*)*matrix)[j * *width + i];
            }
            if (*type == 2) {
                ((float*)(*mas))[j * *width + i] += ((float*)*matrix)[j * *width + i];
            }
            if (*type == 3) {
                ((double*)(*mas))[j * *width + i] += ((double*)*matrix)[j * *width + i];
            }
        }
}

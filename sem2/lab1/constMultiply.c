#define _CRT_SECURE_NO_WARNINGS
#include "constMultiply.h"


void constMultiply(void** mas, int* height, int* width, void** scalar, int* type) {
    if (*type == 1) {
        for (int j = 0; j < *height; j++)
            for (int i = 0; i < *width; i++)
                ((int*)*mas)[j*(*width) + i] *= *(int*)scalar;
    }
    if (*type == 2) {
        for (int j = 0; j < *height; j++)
            for (int i = 0; i < *width; i++)
                ((float*)*mas)[j*(*width) + i] *= *(float*)scalar;
    }
    if (*type == 3) {
        for (int j = 0; j < *height; j++)
            for (int i = 0; i < *width; i++)
                ((double*)*mas)[j*(*width) + i] *= *(double*)scalar;
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void linearly(void** mas, int* height, int* width, int* type, int* fc, void** sc, int* tc) {
    for(int i = 0; i < (*width); i++) {
        if (*type == 1) {
            ((int*)*mas)[*tc*(*width) + i] += *(int*)sc * ((int*)(*mas))[*fc * (*width) + i];
        }
        if (*type == 2) {
            ((float*)*mas)[*tc*(*width) + i] += *(float*)sc * ((float*)(*mas))[*fc * (*width) + i];
        }
        if (*type == 3) {
            ((double*)*mas)[*tc*(*width) + i] += *(double*)sc * ((double*)(*mas))[*fc * (*width) + i];
        }
    }
}

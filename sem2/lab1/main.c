#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "constMultiply.h"
#include "addMatrix.h"
#include "multiply.h"
#include "linearly.h"


int main() {
  int height;
  int width;
  printf("Enter the length of your matrix = ");
  if (scanf("%d", &width) != 1) {
      printf("Wrong!\n");
      exit(-1);
  }
  height = width;
  printf("\n");

  printf("select data type\n 1. int\n 2. float\n 3. double\n");
  int type;
  printf("Your type is ");
  if (scanf("%d", &type) != 1) {
      printf("Wrong!\n");
      exit(-1);
  }
  printf("\n");

  void *mas = 0;
  if (type == 1)
      mas = (int*)malloc(width * height * sizeof(int));
  if (type == 2)
      mas = (float*)malloc(width * height * sizeof(float));
  if (type == 3)
      mas = (double*)malloc(width * height * sizeof(double));
  if (type != 1 & type != 2 & type != 3) {
      printf("Unknown type!\n");
      free(mas);
      exit(-1);
  }
  printf("\n");

  for(int j = 0; j < height; j++)
      for(int i = 0; i < width; i++) {
          if (type == 1) {
              printf("mas[%d][%d] = ", i, j);
              scanf("%d", &((int*)mas)[j*width + i]);
          }
          if (type == 2) {
              printf("mas[%d][%d] = ", i, j);
              scanf("%f", &((float*)mas)[j*width + i]);
          }
          if (type == 3) {
              printf("mas[%d][%d] = ", i, j);
              scanf("%lf", &((double*)mas)[j*width + i]);
          }
      }
  printf("\n");

  for(int j = 0; j < height; j++)
      for(int i = 0; i < width; i++) {
          if (type == 1)
              printf("%d\t%s", ((int*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
          if (type == 2)
              printf("%.7g\t%s", ((float*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
          if (type == 3)
              printf("%.7g\t%s", ((double*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
      }
  printf("\n");

  printf("Welcome to the menu!\n");\
  printf("What arithmetic action do you want to perform on your matrix?\n\n");
  printf("If you want to multiply a matrix by a constant, press 1\n");
  printf("If you want to add matrix to matrix, press 2\n");
  printf("If you want to multiply matrix by matrix, press 3\n");
  printf("If you want to linearly add the rows of your matrix press 4\n");
  printf("If you want exit the programme, press 5\n");

  int choice;
  printf("Your arithmetic action is ");
  scanf("%d", &choice);
  printf("\n");

  while (choice != 5) {
      if(choice == 1) {
          printf("By what amount do you want to multiply your matrix?\n");
          if (type == 1) {
              int scalar;
              scanf("%d", &scalar);
              printf("\n");
              constMultiply(&mas, &height, &width, (void **) &scalar, &type);
          }
          if (type == 2) {
              float scalar;
              scanf("%f", &scalar);
              printf("\n");
              constMultiply(&mas, &height, &width, (void **) &scalar, &type);
          }
          if (type == 3) {
              double scalar;
              scanf("%lf", &scalar);
              printf("\n");
              constMultiply(&mas, &height, &width, (void **) &scalar, &type);
          }

          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)mas)[j*width + i], (i == width - 1) ? "\n" : "");
              }
          printf("\n");
      }

      if(choice == 2) {
          printf("You can only add matrices whose dimensions are the same!\n");
          printf("Please enter another matrix to fill out\n");

          void *matrix = 0;
          if (type == 1)
              matrix = (int*)malloc(width * height * sizeof(int));
          if (type == 2)
              matrix = (float*)malloc(width * height * sizeof(float));
          if (type == 3)
              matrix = (double*)malloc(width * height * sizeof(double));
          printf("\n");

          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%d", &((int*)matrix)[j*width + i]);
                  }
                  if (type == 2) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%f", &((float*)matrix)[j*width + i]);
                  }
                  if (type == 3) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%lf", &((double*)matrix)[j*width + i]);
                  }
              }
          printf("\n");

          printf("Your new matrix:\n");
          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)matrix)[j*width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)matrix)[j*width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)matrix)[j*width + i], (i == width - 1) ? "\n" : "");
              }
          addMatrix(&mas, &height, &width, &type, &matrix);
          free(matrix);
          printf("\n");

          printf("Your original matrix after addition:\n");
          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
              }
          printf("\n");
      }

      if(choice == 3) {
          printf("You can only multiply matrices whose dimensions are the same!\n");
          printf("Please enter another matrix to fill out\n");

          void *matrix = 0;
          if (type == 1)
              matrix = (int*)malloc(width * height * sizeof(int));
          if (type == 2)
              matrix = (float*)malloc(width * height * sizeof(float));
          if (type == 3)
              matrix = (double*)malloc(width * height * sizeof(double));
          printf("\n");

          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%d", &((int*)matrix)[j * width + i]);
                  }
                  if (type == 2) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%f", &((float*)matrix)[j * width + i]);
                  }
                  if (type == 3) {
                      printf("mas[%d][%d] = ", i, j);
                      scanf("%lf", &((double*)matrix)[j * width + i]);
                  }
              }
          printf("\n");

          printf("Your new matrix:\n");
          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)matrix)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)matrix)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)matrix)[j * width + i], (i == width - 1) ? "\n" : "");
              }
          multiply(&mas, &height, &width, &type, &matrix);
          free(matrix);
          printf("\n");

          printf("Your original matrix after addition:\n");
          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
              }
          printf("\n");
      }

      if(choice == 4) {
          printf("What string do you want to use for addition?\n");
          int fc;
          scanf("%d", &fc);
          if (fc > (height - 1)) {
              printf("You are wrong!\n");
              free(mas);
              exit(-1);
          }

          printf("What string do you want to add your string to?\n");
          int tc;
          scanf("%d", &tc);
          if (tc == fc || tc > (height - 1)) {
              printf("You are wrong!\n");
              free(mas);
              exit(-1);
          }

          printf("By what number do you want to multiply the row of your choice for further addition with another row of the matrix?\n");
          if (type == 1) {
              int sc;
              scanf("%d", &sc);
              linearly(&mas, &height, &width, &type, &fc, (void **) &sc, &tc);
          }
          if (type == 2) {
              float sc;
              scanf("%f", &sc);
              linearly(&mas, &height, &width, &type, &fc, (void **) &sc, &tc);
          }
          if (type == 3) {
              double sc;
              scanf("%lf", &sc);
              linearly(&mas, &height, &width, &type, &fc, (void **) &sc, &tc);
          }

          printf("Your original matrix after addition:\n");
          for(int j = 0; j < height; j++)
              for(int i = 0; i < width; i++) {
                  if (type == 1)
                      printf("%d\t%s", ((int*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 2)
                      printf("%.7g\t%s", ((float*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
                  if (type == 3)
                      printf("%.7g\t%s", ((double*)mas)[j * width + i], (i == width - 1) ? "\n" : "");
              }
          printf("\n");
      }

      if(choice != 1 & choice != 2 & choice != 3 & choice != 4 & choice != 5) {
          printf("Wrong!!!\n");
          free(mas);
          printf("Press any button to end the program\n");
          _getch();
          return(-1);
      }

      printf("What arithmetic action do you want to perform on your matrix?\n\n");
      printf("If you want to multiply a matrix by a constant, press 1\n");
      printf("If you want to add matrix to matrix, press 2\n");
      printf("If you want to multiply matrix by matrix, press 3\n");
      printf("If you want to linearly add the rows of your matrix press 4\n");
      printf("If you want exit the programme, press 5\n");

      printf("Your arithmetic action is ");
      scanf("%d", &choice);
      printf("\n");
  }

  free(mas);
  printf("Press any button to end the program\n");
  _getch();
  return 0;
}
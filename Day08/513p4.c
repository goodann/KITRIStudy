
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

#define HEIGHT 3
#define WIDTH 4

int main(void) {
	int **matrix1, **matrix2,**matrix3;
	int i, j, a = 1, b = 12;
	matrix1 = (int**)malloc(sizeof(int*) * HEIGHT);
	matrix2 = (int**)malloc(sizeof(int*) * HEIGHT);
	matrix3 = (int**)malloc(sizeof(int*) * HEIGHT);
	for (i = 0; i < HEIGHT; i++) {
		matrix1[i] = (int*)malloc(sizeof(int) * WIDTH);
		matrix2[i] = (int*)malloc(sizeof(int) * WIDTH);
		matrix3[i] = (int*)malloc(sizeof(int) * WIDTH);

	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			matrix1[i][j] = a++;
			matrix2[i][j] = b--;
		}
	}
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			printf("%3d", matrix3[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;


}



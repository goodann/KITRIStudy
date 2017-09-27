#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main(void) {
	int array1[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i % 2 == 0) {
				array1[i][j] = i * 5 + j + 1;

			}
			else {
				array1[i][j] = i * 5 + (5 - j);

			}

		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", array1[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

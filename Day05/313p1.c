#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>


#pragma warning(disable: 4996)



void print_grap(int *ps, int size) {
	int i,j;
	for (i = 0; i < size; i++) {
		printf("(%d)", ps[i]);
		for (j = 0; j < ps[i] / 5; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main(void) {
	int score[5] = { 72,88,95,64,100 };

	print_grap(score, 5);
	system("pause");
	return 0;
}
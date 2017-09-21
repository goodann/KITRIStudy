#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main(void) {
	int A[3] = { 1,2,3 };
	int B[10];
	int i;
	for (i = 0; i < sizeof(B) / sizeof(int); i++) {
		B[i] = A[i % 3];
	}
	for (i = 0; i < sizeof(B) / sizeof(int); i++) {
		printf("%d ", B[i]);
	}
	system("pause");
	return 0;
}
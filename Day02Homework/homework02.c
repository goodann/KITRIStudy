#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main(void) {
	int lines;
	scanf("%d", &lines);
	//2
	printf("\n=Homework02=\n");
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	printf("\n=Homework03=\n");
	//3
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < lines-i; j++)
			printf("*");
		printf("\n");
	}
	printf("\n=Homework04=\n");
	//4
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < lines - i-1; j++)
			printf(" ");
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}
	printf("\n=Homework05=\n");
	//5
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < i; j++)
			printf(" ");
		for (int j = 0; j < lines-i; j++)
			printf("*");
		printf("\n");
	}

	system("pause");
	return 0;
}
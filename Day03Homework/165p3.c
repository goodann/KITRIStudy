#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main(void) {
	int input;
	float result;

	printf("input electric use :");
	scanf("%d", &input);
	if (input <= 100) {
		result = 370 + input*52.0f;
	}
	else if (input <= 200) {
		result = 660 + 5200 + (input-100)*88.5f;
	}
	else if (input <= 300) {
		result = 1130 + 5200 + 8850 + (input-200)*127.8f;
	}
	else if (input <= 400) {
		result = 2710 + 5200 + 8850 + 12780 + (input - 300)*184.3f;
	}
	else if (input <= 500) {
		result = 5130 + 5200 + 8850 + 12780 + 18430 + (input - 400)*274.3f;
	}
	else {
		result = 9330 + 5200 + 8850 + 12780 + 18430 + 27430 + (input - 500)*494.0f;
	}
	result *= 1.09f;
	printf("result : %.0fwon \n", result);
	system("pause");
	return 0;
}
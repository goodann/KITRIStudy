#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int sum(int input) {
	int i;
	printf("1to %d sum is : %d \n",input,(input*(input + 1)) / 2);
	return input, (input*(input - 1)) / 2;
}
int main(void) {
	int input;
	sum(10);
	sum(100);
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable: 4996)

int main(void) {
	int i, input;
	int count = 0;
	scanf("%d", &input);
	/*
	if (input % 2 == 0) {
		//printf("%d is not PrimeNumber\n", input);
		printf("2 ");
		count++;

	}
	
	for (i = 3; i <= (sqrt(input)) + 1; i+=2){
	*/
	for (i = 2; i <= (input / 2) + 1; i ++) {
		if (input%i == 0) {
			//printf("%d is not PrimeNumber\n",input);
			//break;
			printf("%d ", i);
			count++;
		}
	}
	
	if (count <= 1)
		printf("%d is PrimeNumber\n", input);
	else
		printf("is %d's divisor\n", input);
	system("pause");
	return 0;
}
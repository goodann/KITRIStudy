#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main(void) {
	int a = 10;
	int *pi;
	int **ppi;
	pi = &a;
	ppi = &pi;

	printf("-------------------------------------\n");
	printf("변수     변수값   &연산    *연산     **연산\n");
	printf("-------------------------------------\n");
	printf("-------------------------------------\n");
	printf("  a%10d%10u\n", a, &a);
	printf(" pi%10d%10u%10d\n", pi,&pi,*pi);
	printf("ppi%10u%10u%10u%10u\n", ppi,&ppi,*ppi,**ppi);
	system("pause");
	return 0;
}
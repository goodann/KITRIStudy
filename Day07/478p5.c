#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

void exchange(double*, double*);
void func(void(*fp)(double*,double*),double, double);


int main(void) {
	double a = 10, b = 20;
	func(exchange, a, b);
	system("pause");
	return 0;
}
void exchange(double* a, double* b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}
void func(void(*fp)(double*, double*), double a, double b) {
	printf("%.1lf,%.1lf\n", a, b);
	fp(&a, &b);
	printf("%.1lf,%.1lf\n", a, b);
}
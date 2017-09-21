#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
#define PI 3.141592
#define AGE 30
#define NAME "ssk"
#define SUM(a,b) ((a)+(b))

int main(void) {

	printf("%.2f %d\n", PI,SUM(10,20));

	system("Pause");
	return 0;
}
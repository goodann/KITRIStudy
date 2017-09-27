#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

void reverse(double *pa, int size) {
	int i = 0;
	for (i = 0; i < size/2; i++) {
		double temp = *(pa + i);
		*(pa + i) = *(pa + size - i - 1);
		*(pa + size - i - 1) = temp;

	}
}
int main(void) {
	double ary[] = { 1.5,20.1,16.4,2.3,3.5 };
	int i;
	int tot;
	int score[3][4];
	float avg;
	reverse(ary, sizeof(ary) / sizeof(*ary));
	for (i = 0; i < 5; i++) {
		printf("%.2lf ", ary[i]);
	}

	


	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)



int main(void) {
	double *max, *min;
	printf("�ְ��°� ��������� �Է��ϼ��� : ");
	max = calloc(1, sizeof(double));
	min = calloc(1, sizeof(double));
	scanf("%lf%lf", max, min);
	printf("�ϱ����� %.1lf�Դϴ�.\n", *max - *min);

	system("pause");
	return 0;


}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)



int main(void) {
	double *max, *min;
	printf("최고기온과 최저기온을 입력하세요 : ");
	max = calloc(1, sizeof(double));
	min = calloc(1, sizeof(double));
	scanf("%lf%lf", max, min);
	printf("일교차는 %.1lf입니다.\n", *max - *min);

	system("pause");
	return 0;


}



#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int main(void) {
	double ary1[4] = { 1.5,2.3,7.7,4.9 };
	double ary2[4] = { 3.4,5.2,4.0,9.1 };
	double ary3[4] = { 0.3,7.2,8.4,6.6 };
	int i, j;
	double *pary[3] = { ary1,ary2,ary3 };
	double max = 0;
	int index = 0;
	for (i = 0; i < 3; i++) {
		double avg = 0;
		for (j = 0; j < 4; j++) {
			avg += *(pary[i] + j);
		}
		avg /= 4.0;
		if (avg > max) {
			index = i;
			max = avg;
		}
		
	}
	printf("%d번째 배열 %.1lf %.1lf %.1lf %.1lf\n", index, *(pary[index] + 0), *(pary[index] + 1), *(pary[index] + 2), *(pary[index] + 3));
	printf("average : %.1lf\n",max);
	system("pause");
	return 0;
}
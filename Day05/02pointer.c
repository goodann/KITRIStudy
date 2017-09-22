#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>


#pragma warning(disable: 4996)

void swap(int* a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void treeple(int* a, int* b) {
	*a *= 3;
	//*b *= 3;
	if (*b % 2 == 0) {
		printf("소수가 아닙니다.\n");
		return;
	}
	for (int i = 3; i < sqrt(*b); i+=2) {
		if (*b%i == 0) {
			printf("소수가 아닙니다.\n");
			return;
		}
	}
	printf("소수입니다.\n");

}

int main(void) {
	int a = 10, b = 748943, tot;
	double avg;
	int *pa, *pb;
	int *pt = &tot;
	double* pg = &avg;

	pa = &a;
	pb = &b;
	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	scanf("%d%d", &a, &b);
	treeple(&a, &b);
	printf("두 정수의 값 : %d,%d\n", *pa, *pb);
	printf("두 정수의 핪 : %d\n", *pt);
	printf("두 정수의 평균 : %.1lf\n", *pg);

	system("pause");
	return 0;
}
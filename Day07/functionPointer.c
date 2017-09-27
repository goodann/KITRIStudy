#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

void func(int(*fp)(int, int));
int sum(int, int);
int mul(int, int);
int max1(int, int);


int main(void) {
	int se;
	printf("1. 합\n");
	printf("2. 곱\n");
	printf("3. 큰값 계산\n");
	printf("원하는 작업을 선택하세요 : ");
	scanf("%d", &se);
	switch (se)
	{
	case 1:
		func(sum);
		break;
	case 2:
		func(mul);
		break;
	case 3:
		func(max1);
		break;
	default:
		break;
	}

	system("pause");
	return 0;
}
int sum(int a, int b) {
	return a + b;
}
void func(int(*fp)(int, int)) {
	int a, b;
	int res;
	printf("두 정수값을 입력하세요 : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결과값은 : %d\n", res);
}
int mul(int a, int b) {
	return (a*b);
}
int max1(int a, int b) {
	return ((a>b)?a:b);
}


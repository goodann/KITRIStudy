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
	printf("1. ��\n");
	printf("2. ��\n");
	printf("3. ū�� ���\n");
	printf("���ϴ� �۾��� �����ϼ��� : ");
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
	printf("�� �������� �Է��ϼ��� : ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("������� : %d\n", res);
}
int mul(int a, int b) {
	return (a*b);
}
int max1(int a, int b) {
	return ((a>b)?a:b);
}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>


#pragma warning(disable: 4996)

int main(void) {
	int a, b;
	char c;
	double result;
	scanf("%d%c%d", &a, &c, &b);
	switch (c)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		break;
	}
	printf("%d%c%d=%.2f\n", a, c, b, result);
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
#define true 1
int main()
{
	int sum;

	printf("sum = ");
	scanf("%d", &sum);
	float aver = sum / 3.0f;
	char grade;
	if (aver >= 90)
		grade = 'A';
	else if (aver >= 80)
		grade = 'B';
	else if (aver >= 70)
		grade = 'C';
	else
		grade = 'F';
	printf("average : %.1f grade : %c\n", aver, grade);
	system("pause");

}
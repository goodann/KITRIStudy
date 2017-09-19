#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)


int main(void)
{
	
	int korean = 70;
	int english = 80;
	int math = 90;
	int sum = korean + english + math;
	printf("국어 : %d, 영어 : %d, 수학 : %d\n", korean, english, math);
	printf("총점 : %d\n", sum);

	system("pause");
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	float time;

	printf("time = ");
	scanf("%f", &time);
	int sec = time * 3600;
	
	int min = sec / 60;
	sec %= 60;
	
	int hour = min / 60;
	min %= 60;

	printf("%f time is %d hour %d min %d sec\n", time, hour, min, sec);
	system("pause");

}
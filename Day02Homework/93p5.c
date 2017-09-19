#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int age;
	float height;
	char name[100];
	printf("what your name?");
	scanf("%s", &name);
	printf("what your age and height?");
	scanf("%d%f", &age,&height);
	printf("%s , %d age , %.1fcm\n", name,age,height);
	system("pause");

}
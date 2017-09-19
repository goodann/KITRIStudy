#include<stdio.h>
#include<stdlib.h>
//#pragma warning(disable: 4996)
int main()
{
	int age;
	float height;
	char name[100];
	char bloodGroup[3];
	printf("what your name?");
	scanf_s("%s", &name,100);
	printf("what your age?");
	scanf_s("%d", &age);
	printf("what your height?");
	scanf_s("%f", &height);
	printf("what your blood group?");
	scanf_s("%s", &bloodGroup,3);
	age += 10;
	height -= 0.5f;
	printf("after 10year....\n");
	printf("name : %s\n", name);
	printf("age : %d\n", age);
	printf("height : %.1fcm\n", height);
	printf("boold group : %s\n", bloodGroup);

	system("pause");

}
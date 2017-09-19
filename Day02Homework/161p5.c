
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
#define true 1
int main()
{
	int age = 25;
	int chest = 95;
	char size;
	printf("age = ");
	scanf("%d", &age);

	printf("Chest Size = ");
	scanf("%d", &chest);

	/*
	if (age < 20) {
	if (chest < 85)
	size = 'S';
	else if(chest >= 95)
	size = 'L';
	else
	size = 'M';
	}
	else {
	if (chest < 90)
	size = 'S';
	else if (chest >= 100)
	size = 'L';
	else
	size = 'M';
	}
	*/
	switch (age<20)
	{
	case true:
		switch (chest<85)
		{
		case true:
			size = 'S';
			break;
		default:
			switch (chest >= 95) {
			case true:
				size = 'L';
				break;
			default:
				size = 'M';
			}
		}
		break;
	default:
		switch (chest<90)
		{
		case true:
			size = 'S';
			break;
		default:
			switch (chest >= 100) {
			case true:
				size = 'L';
				break;
			default:
				size = 'M';
			}
		}
		break;
	}
	printf("size is %c.\n", size);
	system("pause");
	return 0;
}


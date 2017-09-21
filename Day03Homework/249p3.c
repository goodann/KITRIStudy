#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

int main(void) {
	int A[3] = { 1,2,3 };
	int B[10];
	int i;
	char str1[80], str2[80];
	char temp[80];

	printf("input two string : ");
	scanf("%s%s", str1, str2);
	printf("before sawp : %s,%s\n", str1, str2);
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("after sawp : %s,%s\n", str1, str2);

	system("pause");
	return 0;
}
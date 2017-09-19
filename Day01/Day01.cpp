// Day01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//콘솔에 출력하는 함수다 _format : 문자열입력
	printf("Hello World!\n");
	printf("Hello KITRI!\n");

	int hp = 100;
	int mp = 20;


	hp = hp - 10;
	printf("player info : hp(%d) mp(%d)\n", hp, mp);
	
	char aa = 'a';
	//int sum = hp + mp;
	int sum = aa;
	float fvalue = 22.22f;
	char arr[10] = { "KITRI" };

	int iValue = fvalue;
	printf("%d\n", iValue);
	printf("arr %s\n", arr);
	printf("aa %c\n", aa);
	printf("sum %d\n", aa);

	int a[5] = { 1,2,3,4,5 };
	printf("a[0] = %d\n", a[0]);
	printf("a[1] = %d\n", a[1]);
	printf("a[2] = %d\n", a[2]);
	printf("a[3] = %d\n", a[3]);
	printf("a[4] = %d\n", a[4]);
	
	a[4] = 7;
	printf("a[0] = %d\n", a[0]);
	printf("a[1] = %d\n", a[1]);
	printf("a[2] = %d\n", a[2]);
	printf("a[3] = %d\n", a[3]);
	printf("a[4] = %d\n", a[4]);

	char fruit[6] = "apple";

	fruit[5] = 'y';
	printf("fruit = %s\n", fruit);
	system("pause");
    return 0;
}
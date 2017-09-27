#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)


int myStrlen(char* ary) {
	int i=0;
	while (i<20 && *(ary + i) != 0) {
		i++;	
	}
	return i;
}

int main(void) {
	

	char fruit[5][20];
	int i, j,len;
	int max = 0;
	int maxI = 0;
	printf("5개의 과일 이름 입력 : ");
	for (i = 0; i < 5; i++) {
		scanf("%s", fruit[i]);

	}
	
	for (i = 0; i < 5; i++) {
		len = 0;
		len = myStrlen(fruit[i]);
		if (max < len) {
			max = len;
			maxI = i;
		}
	}
	printf("길이가 가장 긴 과일 이름은 %s입니다.\n", fruit[maxI]);

	system("pause");
	return 0;
}
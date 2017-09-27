#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
void swap(char * type, void* a, void* b);


int main(void) {
	int age1, age2;
	double height1, height2;
	printf("첫번째 사람의 나이와 키 입력 : ");
	scanf("%d%lf", &age1, &height1);
	printf("두번째 사람의 나이와 키 입력 : ");
	scanf("%d%lf", &age2, &height2);
	swap("int", &age1, &age2);
	swap("double", &height1, &height2);
	printf("첫번째 사람의 나이와 키 : %d,%.1lf\n",age1,height1);
	printf("두번째 사람의 나이와 키 : %d,%.1lf\n", age2, height2);
	system("pause");
	return 0;


}
void swap(char * type, void* a, void* b) {
	if (strcmp(type, "int")) {
		int temp = (*(int*)a);
		*(int*)a = *(int*)b;
		*(int*)b = temp;
	}else if (strcmp(type, "double")) {
		double temp = (*(double*)a);
		*(double*)a = *(double*)b;
		*(double*)b = temp;
	}

}

#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
struct student {
	int num;
	char name[20];
	int score[5];
	double avg;
};
int main() {
	struct student studentA = { 315,"hongGildong",{82,93,74,90,65} };
	int sum=0;
	int i;
	for (i = 0; i < 5; i++)
		sum += studentA.score[i];
	studentA.avg = sum / 5.0;
	//scanf("%d%d", &crackerA.price, &crackerA.calories);
	printf("number : %d\n", studentA.num);
	printf("name : %s\n", studentA.name);
	printf("score : ");
	for (i = 0; i < 5; i++)
		printf(" %d ",studentA.score[i]);
	printf("\n");
	printf("average : %.1f\n", studentA.avg);
	system("pause");
	return 0;
}

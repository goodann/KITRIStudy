/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

struct list {
	int num;
	struct list *next;
};

int main(void) {
	struct list a = { 10,0 }, b = { 20,0 }, c = { 30,0 };
	struct list *head = &a, *current;
	a.next = &b;
	b.next = &c;
	printf("head->num : %d\n", head->num);
	printf("head->next>num : %d\n", head->next->num);

	printf("list all : ");

	current = head;
	while (current != NULL) {
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");
	system("pause");
	return 0;


}
*/
//17-12
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

enum season{ SPRING, SUMMER, FALL, WINTER };

int main(void) {
	enum season ss;
	char *pc=NULL;
	ss = WINTER;
	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swimming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "skiing";
		break;
	default:
		break;
	}
	printf("나의 레저 활동 => %s\n", pc);
	system("pause");
	return 0;


}
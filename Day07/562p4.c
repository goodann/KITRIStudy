#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
enum{NUMBER = 1,PHONE_NUMBER};
typedef union {
	int num;
	char phone[20];
}Password;
int main(void) {
	Password first;

	int i;
	printf("원하는 비밀번호 입력방식 : ");
	scanf("%d", &i);
	printf("비밀번호 입력 : ");
	switch (i)
	{
	case NUMBER:
		scanf("%d", &first.num);
		printf("입력한 비밀번호 : %d\n",first.num);

		break;
	case PHONE_NUMBER:
		scanf("%s", &first.phone);
		printf("입력한 비밀번호 : %s\n",first.phone);
		break;
	default:
		break;
	}
	
	system("pause");
	return 0;


}
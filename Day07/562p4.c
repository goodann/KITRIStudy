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
	printf("���ϴ� ��й�ȣ �Է¹�� : ");
	scanf("%d", &i);
	printf("��й�ȣ �Է� : ");
	switch (i)
	{
	case NUMBER:
		scanf("%d", &first.num);
		printf("�Է��� ��й�ȣ : %d\n",first.num);

		break;
	case PHONE_NUMBER:
		scanf("%s", &first.phone);
		printf("�Է��� ��й�ȣ : %s\n",first.phone);
		break;
	default:
		break;
	}
	
	system("pause");
	return 0;


}
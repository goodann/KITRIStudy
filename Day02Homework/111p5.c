#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main()
{
	int hard, soft, money;
	printf("hard price = 70 , how much?");
	scanf("%d", &hard);
	printf("soft price = 30 , how much?");
	scanf("%d", &soft);
	printf("how much have money?");
	scanf("%d", &money);
	
	printf("hard price = %d won , soft price = %d won\n", hard*70, soft*30);
	money -= (hard * 70 + soft * 30);
	printf("have money %d won\n", money);
	int coin500 = money / 500;
	money %= 500;
	int coin100 = money / 100;
	money %= 100;
	int coin50 = money / 50;
	money %= 50;
	int coin10 = money / 10;
	coin10 %= 10;

	printf("500 won coin %d, 100won coin %d, 50won coin %d, 10won coin %d\n", coin500, coin100, coin50, coin10);
	system("pause");

}
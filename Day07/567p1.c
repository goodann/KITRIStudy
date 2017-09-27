#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
struct money_box{
	int w500;
	int w100;
	int w50;
	int w10;

};
typedef struct money_box MoneyBox;
void init(MoneyBox *s);
void save(MoneyBox *s, int unit, int cnt);
int total(MoneyBox *s);
int main(void) {
	MoneyBox mb;
	init(&mb);
	int a, b;
	while (1) {
		printf("동전의 금액과 개수 : ");
		scanf("%d", &a);
		if (a == -1)
			break;
		scanf("%d", &b);
		save(&mb, a, b);
	}
	printf("총 저금액 : %d원\n",total(&mb));
	system("pause");
	return 0;
}

void init(MoneyBox *s) {
	s->w10 = 0;
	s->w100 = 0;
	s->w50 = 0;
	s->w500 = 0;

}
void save(MoneyBox *s, int unit, int cnt) {
	switch (unit)
	{
	case 10:
		s->w10 += cnt;
		break;
	case 100:
		s->w100 += cnt;
		break;
	case 50:
		s->w50 += cnt;
		break;
	case 500:
		s->w500 += cnt;
		break;
	default:
		break;
	}
}
int total(MoneyBox *s) {
	return (s->w10*10 + s->w100*100 + s->w50*50 + s->w500*500);
}
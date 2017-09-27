
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)


int hour, minite;
void set(int h, int m);
void show(void);
void move(void);

int main(void) {
	int i, j;
	scanf("%d%d", &i, &j);
	set(i, j);
	show();
	scanf("%d", &j);
	for (i = 0; i < j; i++) {
		move();
	}
	show();
	system("pause");
	return 0;


}

void set(int h, int m) {
	hour = h;
	minite = m;
}
void show(void) {
	if (hour > 12) {
		printf("%d시 %d분(PM)\n", hour-12, minite);
	

	}
	else if (hour == 12) {
		printf("%d시 %d분(PM)\n", hour, minite);
	}else {
		printf("%d시 %d분(AM)\n", hour, minite);
	}

	
}
void move(void) {
	minite++;
	hour += (minite / 60);
	hour %= 24;
	minite %= 60;
}


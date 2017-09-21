#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
struct cracker {
	int price;
	int calories;
};
int main() {
	struct cracker crackerA;
	scanf("%d%d", &crackerA.price, &crackerA.calories);
	printf("price = %dwon \ncalories = %dkcal", crackerA.price, crackerA.calories);
	system("pause");
	return 0;
}

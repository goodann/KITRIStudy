#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

void rotate(int **a) {
	int i = 0;
	int *temp;
	temp = *a;
	*a = *(a + 1);

	*(a + 1) = *(a + 2);
	*(a + 2) = temp;
}
int main(void) {
	char get;
	scanf("%c", &get);
	int a = 10, b = 20, c = 30;
	int *arr[3] = { &a,&b,&c };
	while (get == '\n') {
		rotate(&arr[0], &arr[1], &arr[2]);
		printf("%u %u %u | %d %d %d", arr[0], arr[1], arr[2], *arr[0], *arr[1], *arr[2]);
		scanf("%c", &get);
	}
	system("pause");
	return 0;
}
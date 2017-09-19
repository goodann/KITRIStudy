#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
int main(void) {
	int start, end;
	scanf("%d%d", &start, &end);
	for (int i = start; i <= end; i++) {
		for (int j = 2; j < 10; j++) {
			printf("%d * %d = %d\n", i, j, i*j);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
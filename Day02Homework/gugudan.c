#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (int j = 2; j < 10; j++) {
		for (int i = 1; i < 10; i++) {
			printf("%d * %d = %d\n", j, i, i * j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


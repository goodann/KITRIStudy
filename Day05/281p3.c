#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>


#pragma warning(disable: 4996)

void rotate(int *pa, int *pb, int *pc) {
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
}


int main(void) {
	char get;
	scanf("%c", &get);
	int arr[3] = { 1,2,3 };
	while (get == '\n') {
		rotate(&arr[0], &arr[1], &arr[2]);
		printf("%d %d %d", arr[0], arr[1], arr[2]);
		scanf("%c", &get);
	}
	system("pause");
	return 0;
}
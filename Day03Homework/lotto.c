#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<time.h>
#pragma warning(disable: 4996)

int main(void) {
	int answer[7];
	int i,j;
	srand(time(NULL));
	for (i = 0; i < 7; i++) {
		answer[i] = rand() % 45 + 1;
		j = 0;
		int isOverlap = 0;
		for (j = 0; j < i; j++) {
			if (answer[j] == answer[i]) {
				i--;
				isOverlap = 1;
				break;
			}
		}
		if (isOverlap)
			continue;
	}

	for (i = 0; i < 7; i++) {
		int min = INT_MAX;
		int minIndex = 0;

		for (j = i; j < 7; j++) {
			if (min > answer[j]) {
				min = answer[j];
				minIndex = j;
			}
		}
		for (j = minIndex; j > i; j--) {
			answer[j] = answer[j - 1];
		}
		answer[i] = min;
	}
	for (i = 0; i < 7; i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
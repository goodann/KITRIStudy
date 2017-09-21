#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable: 4996)

int main() {
	int answer[3];
	int input[3];
	int i,j;
	int result[3];
	srand(time(NULL));
	for (i = 0; i < 3; i++) {
		answer[i] = rand() % 9+1;
		for (int j = 0; j < i; j++) {
			if (answer[j] == answer[i]) {
				i--;
				break;
			}
		}
	}
	printf("%d%d%d\n", answer[0], answer[1], answer[2]);
	while (1) {
		for (i = 0; i < 3; i++) {
			result[i] = 0;
		}
		scanf("%d%d%d", &input[0], &input[1], &input[2]);
		for (i = 0; i < 3; i++) {
			int j;
			for (j = 0; j < 3; j++) {
				if (input[i] == answer[j]) {
					if (i == j) {
						result[0]++;
						break;
					}
					else {
						result[1]++;
						break;
					}
				}

			}
			if (j == 3) {
				result[2]++;
			}
		}
		printf("Result = %dStrike! %dball! %dout!\n", result[0], result[1], result[2]);
		if (result[0] == 3)
			break;
	}
	system("pause");
	return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

void pointerSwap(int **a, int** b) {
	int* temp = *a;
	*a = *b;
	*b = temp;
}
int main(void) {
	int matrix1[2][2], matrix2[2][2],result[2][2];
	int i,j,k,mux;
	char temp[10];
	printf("연산자를 입력하세요 (+,-,mul,mux)");
	scanf("%s", temp);
	printf("배열1을 입력하세요\n");
	for (i = 0; i < 2; i++) {
		scanf("%d%d", &matrix1[i][0], &matrix1[i][1]);
	}
	if (strcmp(temp, "mux") == 0) {
		printf("계수를 입력하세요\n");
		scanf("%d", &mux);

	}
	else {
		printf("배열2을 입력하세요\n");
		for (i = 0; i < 2; i++) {
			scanf("%d%d", &matrix2[i][0], &matrix2[i][1]);
		}
	}
	
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			if (strcmp(temp, "+") == 0) {
				result[i][j] = matrix1[i][j] + matrix2[i][j];
			}
			else if (strcmp(temp, "-") == 0) {
				result[i][j] = matrix1[i][j] - matrix2[i][j];
			}else if (strcmp(temp, "mul") == 0) {
				int value = 0;
				for (k = 0; k < 2; k++) {
					value += matrix1[i][k] * matrix2[k][j];
				}
				result[i][j] = value;
					
			}else if (strcmp(temp, "mux") == 0) {
				result[i][j] = matrix1[i][j] * mux;
			}
				
		}
	}
			
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable: 4996)


int main(void) {
	
	int answer,input;
	srand(time(NULL));
	answer = rand() % 30;
	while (1) {
		printf("input number(1~30):");
		scanf("%d", &input);
		if (input < answer) {
			printf("Bigger then %d\n", input);
		}
		else if(input>answer){
			printf("Smaller then %d\n", input);
		}
		else {
			printf("%d is Answer\n", input);
			break;
		}
	}
	system("pause");
	return 0;
}

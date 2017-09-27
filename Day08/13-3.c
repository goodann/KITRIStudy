
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
/*
void assign10(void);
void assign20(void);

int a;
int main(void) {
	printf("함수 호출 전 a값 : %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a값 : %d\n", a);


	system("pause");
	return 0;


}

void assign10(void) {
	a = 10;
}
void assign20(void) {
	int a;
	a = 20;
}
*/
//13-4

/*
void auto_func(void);
void static_func(void);

int main(void) {
	int i;
	printf("auto 지역 변수를 사용한 함수...\n");
	for (i = 0; i < 3; i++) {
		auto_func();


	}


	printf("tatic 지역 변수를 사용한 함수...\n");

	for (i = 0; i < 3; i++) {
		static_func();
	}
	system("pause");

	return 0;
}

void auto_func(void) {
	auto int a = 0;
	a++;
	printf("%d %u\n", a,&a);
}
void static_func(void) {

	static int a;
	a++;
	printf("%d\n", a);
}

*/
//16-1

/*
int main(void) {
	int * pi;
	int i,sum=0;
	double *pd;
	pi = (int*)malloc(5*sizeof(int));
	if (pi == NULL) {
		printf("#으로 메모리가 부족합니다.\n");
	}
	pd = (double *)malloc(sizeof(double));
	pd = 0;
	for (i = 0; i < 5; i++) {
		scanf("%d", &pi[i]);
		sum += pi[i];

	}
	printf("sum : %.1lf\n", (sum / 5.0));

	printf("정수형으로 사용 :%d\n", *pi);
	printf("실수형으로 사용 : %lf\n", *pd);
	free(pi);
	free(pd);
	system("pause");

	return 0;
}
*/

/*
int main(void) {
	int * pi;
	int i, num = 0;
	int size = 5;
	int count = 0;
	pi = (int*)calloc(size, sizeof(int));
	while (1){

		scanf("%d", &num);
		if (num <= 0)
			break;
		if (count == size) {
			size += 5;
			pi=(int*)realloc(pi, size * sizeof(int));
			
		}	
		pi[count++] = num;
	}

	for (i = 0; i < count; i++) {
		printf("%5d", pi[i]);

	}
	free(pi);
	printf("\n====================\n");
	system("pause");

	return 0;
}

*/

void print_str(char** ps);

int main(void) {
	char temp[80];
	char* str[21] = { 0, };
	int i = 0;
	while (i < 20) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		if (strcmp(temp, "end") == 0)
			break;
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str);
	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);

	}
	system("pause");
	return 0;
}





void print_str(char** ps) {
	while (*ps != NULL) {
		printf("%s\n", *ps);
		ps++;
	}

}

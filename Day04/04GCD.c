#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdint.h>


#pragma warning(disable: 4996)

int euclidean(int a, int b) {
	int temp;
	if (a > b) {
		temp = a;
		a = b;
		b = temp;
	}
	temp = b%a;
	if (temp == 0)
		return a;
	return euclidean(a, temp);
}

int main(void) {
	int a, b;
	int gcd;
	uint64_t i;
	scanf("%d%d", &a, &b);
	if (a > b) {
		i = a;
		a = b;
		b = i;
	}

	gcd = euclidean(a, b);
	i = (uint64_t)(a)*(uint64_t)(b) / gcd;
	printf("%d and %d 's Greatest common divisor is %d\n", a, b, gcd);
	printf("%d and %d 's least common multiple is %llu\n", a, b, i);

	system("Pause");
	return 0;
}

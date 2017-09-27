#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

int countNum(int ary1[][4], int ary2[][4], int* ary3[][2]) {
	int i, j;
	int count=0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (ary1[i][j] == ary2[i][j]) {
				ary3[count][0] = i;
				ary3[count][1] = j;
				count++;
			}
		}
	}
	return count;

}


int main(void) {
	int ary1[3][4] = {
		{ 15,3,9,11 },
		{ 23,7,10,12 },
		{ 0,17,55,24 }
	};
	int ary2[3][4] = {
		{ 13,8,9,15 },
		{ 23,0,10,11 },
		{ 29,17,43,3 }
	};
	int sameNum[12][2];
	int i, j;
	int count=0;
	count = countNum(ary1, ary2, sameNum);
	printf("일치하는 번호의 수 %d\n", count);
	printf("배열에서의 위치 (행,열)...\n");
	for (i = 0; i < count; i++) {
		printf("(%d,%d)\n", sameNum[i][0], sameNum[i][1]);
	}
	system("pause");
	return 0;
}

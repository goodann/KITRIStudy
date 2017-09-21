#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable: 4996)
typedef struct {
	char name[20];
	double grade;
	int english;
}profile;

void input_data(profile staffs[]) {
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%s%lf%d", &(staffs[i].name), &staffs[i].grade, &staffs[i].english);
	}
}
void elite(profile staffs[]) {
	int i;
	printf("Elete is \n");
	for (i = 0; i < 5; i++) {
		if (staffs[i].grade >= 4.0 && staffs[i].english >= 900) {
			printf("%s, %.1lf %d\n", staffs[i].name, staffs[i].grade, staffs[i].english);
		}
	}
	printf("\n");
}

int main(void) {
	profile new_staff[5];
	input_data(new_staff);
	elite(new_staff);
	system("pause");
	return 0;
}
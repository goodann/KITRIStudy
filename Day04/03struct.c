#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)
#pragma pack(10)
struct  student
{
	int num;
	double grade;

};
struct profile
{
	char name[20];
	int age;
	double height;
	struct student stu;


};
int main(void) {

	struct student s1;
	struct profile ssk;

	strcpy(ssk.name, "SSK");
	ssk.age = 26;
	ssk.height = 177;
	ssk.stu.num = 100;
	ssk.stu.grade = 4.5;

	s1.num = 100;
	s1.grade = 4.5;

	printf("num = %d grade = %.1f\n", s1.num, s1.grade);
	printf("struct student size = %d, profile = %d\n", sizeof(struct student),sizeof(struct profile));
	system("Pause");
	return 0;
}

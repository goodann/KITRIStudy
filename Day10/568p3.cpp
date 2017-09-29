#include <iostream>
#include <string>

using namespace std;
namespace myName {
	class student {
		int number;
		string name;
		int korean;
		int english;
		int math;
		int sum;
		double average;
		char grade;
		void calcTotal() {
			sum = korean + english + math;
		}
		void calcAverage() {
			average = sum / 3.0;
		}
		void setGrade() {
			if (average >= 90) {
				grade = 'A';
			}
			else if (average >= 80) {
				grade = 'B';
			}
			else if (average >= 70) {
				grade = 'C';
			}
			else {
				grade = 'F';
			}
		}
	public:
		student():number(0),name(""),korean(0),english(0),math(0),sum(0),average(0),grade('F') {}
		student(int number1, string name1, int korean1, int english1, int math1) :number(number1), name(name1), korean(korean1), english(english1), math(math1),sum(korean + english + math), average (sum / 3.0) {
			if (average >= 90) {
				grade = 'A';
			}
			else if (average >= 80) {
				grade = 'B';
			}
			else if (average >= 70) {
				grade = 'C';
			}
			else {
				grade = 'F';
			}
		}
		int getNumber() { return number; }
		string getName() { return name; }
		int getKorean() { return korean; }
		int getEnglish() { return english; }
		int getMath() { return math; }
		int getSum() { return sum; }
		double getAverage() { return average; }
		char getGrade() { return grade; }

		
		void setData(int number1, string name1, int korean1, int english1, int math1) {
			number = number1;
			name = name1;
			korean = korean1;
			english = english1;
			math = math1;
			calcTotal();
			calcAverage();
			setGrade();
			
		}


	};
}



void InsertionSort(myName::student* stu) {
	for (int i = 0; i < 5; i++) {
		int max = 0;
		int maxIndex = i;
		for (int j = i; j < 5; j++) {
			if (max < stu[j].getSum()) {
				max = stu[j].getSum();
				maxIndex = j;
			}
		}
		myName::student temp = stu[i];
		stu[i] = stu[maxIndex];
		stu[maxIndex] = temp;
	}
}

int main(void) {
	myName::student* stu;

	stu = new myName::student[5];
	for(int i=0;i<5;i++){
		int number=0, korean=0,english=0, math=0;
		string name;
		cout << "학번 : ";
		cin >> number;
		cout << "이름 : ";
		cin >> name;
		cout << "국어, 영어, 수학 점수 : ";
		cin >> korean >> english >> math;
		stu[i].setData(number, name, korean, english, math);
		
	}
	cout << endl << "# 정렬 전 데이터..." << endl;
	for (int i = 0; i<5; i++) {
		cout << stu[i].getNumber() << " " << stu[i].getName() << " "
			<< stu[i].getKorean() << " " << stu[i].getEnglish() << " " << stu[i].getMath() << " " << stu[i].getSum() << " " << stu[i].getAverage() << " " << stu[i].getGrade() << endl;
	}
	InsertionSort(stu);
	cout << endl << "# 정렬 후 데이터..." << endl;
	for (int i = 0; i<5; i++) {
		cout << stu[i].getNumber() << " " << stu[i].getName() << " "
			<< stu[i].getKorean() << " " << stu[i].getEnglish() << " " << stu[i].getMath() << " " << stu[i].getSum() << " " << stu[i].getAverage() << " " << stu[i].getGrade() << endl;
	}
	delete[] stu;

	system("pause");
	return 0;
}


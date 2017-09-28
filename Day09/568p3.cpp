#include <iostream>
#include <string>
using namespace std;
namespace myName {
	struct student {
		int number;
		string name;
		int korean;
		int english;
		int math;
		int sum;
		double average;
		char grade;
	};
}



void InsertionSort(myName::student stu[]) {
	for (int i = 0; i < 5; i++) {
		int max = 0;
		int maxIndex = i;
		for (int j = i; j < 5; j++) {
			if (max < stu[j].sum) {
				max = stu[j].sum;
				maxIndex = j;
			}
		}
		myName::student temp = stu[i];
		stu[i] = stu[maxIndex];
		stu[maxIndex] = temp;
	}
}

int main(void) {
	myName::student stu[5];

	for (auto &st : stu) {
		cout<<"학번 : ";
		cin >> st.number;
		cout << "이름 : ";
		cin >> st.name;
		cout << "국어, 영어, 수학 점수 : ";
		cin >> st.korean >> st.english >> st.math;
		st.sum = st.korean + st.english + st.math;
		st.average = st.sum / 3.0;
		if (st.average >= 90) {
			st.grade = 'A';
		}
		else if (st.average >= 80) {
			st.grade = 'B';
		}
		else if (st.average >= 70) {
			st.grade = 'C';
		}
		else {
			st.grade = 'F';
		}
	}
	cout << endl << "# 정렬 전 데이터..." << endl;
	for (auto st : stu) {
		cout << st.number << " " << st.name << " "
			<< st.korean << " " << st.english << " " << st.math << " " << st.sum << " " << st.average << " " << st.grade << endl;
	}
	InsertionSort(stu);
	cout << endl << "# 정렬 후 데이터..." << endl;
	for (auto st : stu) {
		cout << st.number << " " << st.name << " " 
			<< st.korean << " " << st.english << " " << st.math << " " <<st.sum<< " " << st.average << " " << st.grade << endl;
	}
	system("pause");
	return 0;
}
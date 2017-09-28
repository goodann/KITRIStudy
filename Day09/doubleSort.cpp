
#include<iostream>
using namespace std;

template<typename T>

void boubleSort(T a[],int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size-i; j++) {
			if (a[j - 1] > a[j]) {
				T temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}


int main(void) {
	constexpr int arrSize = 10;
	int arr[arrSize] = { 9,8,5,7,6,4,3,1,20,2 };
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
	boubleSort(arr, arrSize);
	for (auto item : arr)
		cout << item << " ";
	cout << endl;
	system("pause");
	return 0;
}
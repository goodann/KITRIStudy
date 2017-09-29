#include<string>
#include<cstdio>
#include<iostream>
#include<stdio.h>
using namespace std;


class CMyData {
public:
	CMyData(int nParam) :m_nData(nParam) {};

	void printData() {
		cout << m_nData << endl;

		cout << CMyData::m_nData << endl;

		cout << this->m_nData << endl;
		cout << this->CMyData::m_nData << endl;

	}
private:
	int m_nData;

};

int main(void) {
	CMyData a(5), b(10);
	a.printData();
	b.printData();
	return 0;
}








//
//class cMyPoint {
//public:
//	cMyPoint(int x) {
//		cout << "CMyPoint(int)" << endl;
//		if (x > 100)
//			m_x = 100;
//		else
//			m_x = x;
//	}
//	cMyPoint(int x, int y) :cMyPoint(x) {
//		cout << "CMyPoint(int,int)" << endl;
//		if (y > 200)
//			m_y = 200;
//		else
//			m_y = y;
//	}
//	void Print() {
//		cout << "X:" << m_x << endl;
//		cout << "Y:" << m_y << endl;
//	}
//private:
//	int m_x = 0;
//	int m_y = 0;
//
//};
//int main(void) {
//	cMyPoint ptBegin(110);
//	ptBegin.Print();
//	cMyPoint ptEnd(50, 250);
//	ptEnd.Print();
//	return 0;
//}
//
//


/*
class a {
public:

	a() {
		cout << "a()" << endl;
	}

	
	a(a &A) {
	cout << "a(a&)" << endl;
	}
	
	a(int a) {
		cout << "a(int)" << endl;
	}
	~a() {
		cout << "~a()" << endl;
	}
};
class b :public a {
public:
	b() :a(1) {
		cout << "b()" << endl;
	}
	
	b(b &B):a(B) {
	cout << "b(b&)" << endl;
	}
	
	~b() {
		cout << "~b()" << endl;
	}
};

class c {
public:
	c(a &a) {
		cout << "c(a&)" << endl;
	}
	c() {
		cout << "c()" << endl;
	}
	c(c &C) {
		cout << "c(c&)" << endl;
	}
	virtual ~c() {
		cout << "~c()" << endl;
	}
	int cc() {

	}
};
class d :virtual public c {
	int ee() {

	}
public:
	d() :c() {
		cout << "d()" << endl;
	}
	d(d &D) {
		cout << "d(d&)" << endl;
	}
	virtual ~d() {
		cout << "~d()" << endl;
	}
};



c hi(a AA, b BB) {
	cout << "hi(a,b);" << endl;
	c CC(AA);
	cout << "return CC;" << endl;
	return CC;
}
int main(int argc, char* argv[]) {

	cout << "a AA(1);" << endl;
	a AA(1);
	cout << "a* AP = nullptr;" << endl;
	a* AP = nullptr;
	cout << "b BB;" << endl;
	b BB;
	cout << "b* BP = nullptr;;" << endl;
	b* BP = nullptr;
	cout << "AP = new b();" << endl;
	AP = new b();
	cout << "BP = new b();" << endl;
	BP = new b();
	cout << "c C1=hi(AA,BB);" << endl;
	c C1 = hi(AA, BB);
	cout << "delete AP;" << endl;
	delete AP;
	cout << "delete BP;" << endl;
	delete BP;
	cout << "c CC;" << endl;
	c CC;
	cout << "d DD;" << endl;
	d DD;
	cout << "c *CP = new c(CC);" << endl;
	c *CP = new c(CC);
	cout << "c *DP = new d();" << endl;
	c *DP = new d();
	cout << "delete CP;" << endl;
	delete CP;
	cout << "delete DP;" << endl;
	delete DP;
	cout << "d* DDP = new d(DD);" << endl;
	d* DDP = new d(DD);
	cout << "delete DDP;" << endl;
	delete DDP;
	cout << "============================" << endl;
	return 0;
}

*/
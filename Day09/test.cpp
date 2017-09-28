#include<string>
#include<cstdio>
#include<iostream>
#include<stdio.h>
using namespace std;
class a {
public:
	/*
	a() {
		cout << "a()" << endl;
	}
	*/
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
	b():a(1) {
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
	d():c() {
		cout << "d()" << endl;
	}
	d(d &D) {
		cout << "d(d&)" << endl;
	}
	virtual ~d() {
		cout << "~d()" << endl;
	}
};



int Add(int a, int b, int c) {
	std::cout << "Add(int,int,int):";
	return a + b + c;
}
int Add(int a, int b) {
	std::cout << "Add(int,int):";
	return a + b;
}
double Add(double a, double b) {
	std::cout << "Add(double,double):";
	return a + b;
}
int TestFunc(int par1, int par2 = 2) {
	return par1*par2;
}

c hi(a AA, b BB) {
	cout << "hi(a,b);" << endl;
	c CC;
	cout << "return CC;" << endl;
	return CC;
}

void TestFunc(void) {
	cout << "::TestFunc()" << endl;
}

int global = 100;

namespace Test {
	int global = 200;
	void TestFunc(void) {
		cout << "Test::TestFunc()" << endl;
	}
}
using namespace Test;

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
	c C1=hi(AA,BB);
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
	std::cout << Add(1,2,3) << std::endl;
	std::cout << Add(10,5) << std::endl;
	std::cout << Add(1.1,2.2) << std::endl;

	//TestFunc();
	::TestFunc();
	Test::TestFunc();

	int ko[] = { 1,2,3,4,5 };

	for (auto &k : ko) {
		k = 20;
	}

	for (auto k : ko) {
		cout << k << " ";
	}
	cout << endl;
	int ary[3][4];
	int i = 1;
	for (auto& n : ary) {
		for (auto& p : n) {
			p = i++;
		}
	}
	for (auto& n : ary) {
		for (auto& p : n) {
			cout << p << " ";
		}
		cout << endl;
	}
	cout << endl;
	::global = 200;
	system("pause");
	return 0;
}


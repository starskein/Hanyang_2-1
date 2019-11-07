#include <iostream>
#include <string>
using namespace std;

class A{
	public:
		A(int);
		~A();
		virtual void print();
	private:
		int* memberA;
};
class B : public A{
	public:
 		B(double);
		~B();
		virtual void print();
	private:
		double* memberB;
};
class C: public B{
	public:
		C(string);
		~C();
		virtual void print();
	private:
		string* memberC;
};

#include <iostream>
#include <vector>
#include "print_member.h"
using namespace std;

int main(){
	int a_;
	double b_;
	string str;
	cin >> a_ >> b_ >> str;
	vector<A*> vec;
	A* a = new A(a_);
	B* b = new B(b_);
	C* c = new C(str);
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	for(int i =0; i<3;i++){
		vec[i]->print();
	}
	delete a;
	delete b;
	delete c;
	
}


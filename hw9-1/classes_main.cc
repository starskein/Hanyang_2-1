#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;
int main(){
	vector<A*> vec;
	A *a = new A;
	A *b = new B;
	A *c = new C;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	vector<A*>::iterator itr=vec.begin();
	vec[0]->test();
	vec[1] -> test();
	vec[2] -> test();
	delete a;
	delete b;
	delete c;
}

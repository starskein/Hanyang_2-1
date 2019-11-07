#include <iostream>
#include <string>
#include <vector>
#include "print_info.h"
using namespace std;
void printObjectTypeInfo1(A* object){
	string str = object->getTypeInfo();
	cout << str << endl;
}
void printObjectTypeInfo2(A& object){
        string str = object.getTypeInfo();
        cout << str << endl;
}
int main(){
	vector<A*> vec;
	A* a = new A;
	A* b = new B;
	A* c = new C;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	printObjectTypeInfo1(vec[0]);
	printObjectTypeInfo2(*vec[0]);
	printObjectTypeInfo1(vec[1]);
	printObjectTypeInfo2(*vec[1]);
	printObjectTypeInfo1(vec[2]);
        printObjectTypeInfo2(*vec[2]);
	delete a;
	delete b;
	delete c;
	return 0;
}


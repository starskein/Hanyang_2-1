#include <iostream>
#include <string>
#include <vector>
#include "class_function.h"
using namespace std;

int main(){
	vector<A*> vec;
	while(1){
		
		string str;
		cin >> str;
		if(str =="0") break;
		else if(str=="B"){
			B* b = new B;
			vec.push_back(b);
		}
		else if(str =="C"){
			C* c = new C;
			vec.push_back(c);
		}
		else{
			BB* bb = new BB;
			vec.push_back(bb);
		}
	}
	for(int i=0;i<vec.size();i++){
		vec[i]->test1();
		vec[i]->test2();
	}
	for(int i=0;i<vec.size();++i) delete vec[i];
	vec.clear();
	return 0;
}

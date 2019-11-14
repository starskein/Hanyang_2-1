#include <iostream>
#include "Animals.h"
#include <vector>
using namespace std;
int main(){
	string check,str,str2;
	int a,b;
	vector<Animal*> vec;
	cin >> check;
	while(1){
		if(check=="0") break;
		else if (check == "z"){
			cin >> str >> a >> b;
			Zebra* z = new Zebra(str,a,b);
			vec.push_back(z);
		}
		else if (check == "c"){
			cin >> str >> a >> str2;
                        Cat* c = new Cat(str,a,str2);
                        vec.push_back(c);
                }
		cin >> check;
	}
	for(vector<Animal*>::iterator itr = vec.begin();itr!=vec.end();itr++){
		(*itr)->printInfo();
	}
}


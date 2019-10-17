#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "integer_set.h"
using namespace std;

int main(){
	IntegerSet intarr;
	string str;
	getline(cin,str);
	while(str != "quit"){
		if (str.find("add") != string::npos){
			intarr.AddNumber(str[4]-'0');
			intarr.Print();
		}
		else if (str.find("del") != string::npos){
                        intarr.DeleteNumber(str[4]-'0');
			intarr.Print();          
                }
		else if (str.find("get") != string::npos){
                        int k = intarr.GetItem(str[4]-'0');  
			cout << k << endl;        
                }
		getline(cin,str);
	}
	return 0;
}

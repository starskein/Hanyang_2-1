#include <iostream>
#include <string>
#include "world_clock.h"

using namespace std;

int main(){
	WorldClock wc;
	
	while(true){
		string str;
		cin >> str;
		if(str == "quit")
			break;
		if(str == "set"){
			cin >> wc;
			cout << wc<<endl;
		}
		else if (str == "tick"){
			int t;
			cin >> t;
			wc.Tick(t);
			cout << wc<<endl;
		}
	}
	return 0;
}

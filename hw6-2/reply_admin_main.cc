#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include "reply_admin.h"
using namespace std;
int main(void){
	string inputs;
	ReplyAdmin admin;
	while(1){
		getline(cin, inputs);
		bool check;
		if(inputs == "#quit") break;
		else if(inputs.find("#remove") != string::npos){
			if(inputs.find("-") != string::npos){
				int i=inputs.find("-");
				check = admin.removeChat(inputs[i-1]-'0',inputs[i+1]-'0');
				}
			else{
				check = admin.removeChat(inputs[8]-'0');
			}
		}
		else{
			check = admin.addChat(inputs);
		}
		if (check==false)
			cout << "error occured" <<endl;
		else
			admin.printChat();
	}
	return 0;
}

		
			
			

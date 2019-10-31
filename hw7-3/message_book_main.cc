#include <iostream>
#include "message_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

int main(){
	MessageBook mb;
	while(1){
		string line;
		string p[10];
		char line_c[50];
		getline(cin,line);
		strcpy(line_c,line.c_str());
		char* ptr = strtok(line_c," ");
                int i=0;
                while (ptr != NULL){
                        p[i] = ptr;
			if(i>2) p[2] += " " + p[i];
                        ptr = strtok(NULL, " ");
                        i++;
                }
		if (p[0] == "quit") break;
		else if (p[0] == "add") mb.AddMessage(atoi(p[1].c_str()),p[2]);
		else if (p[0] == "delete") mb.DeleteMessage(atoi(p[1].c_str()));
		else if (p[0] == "print"){
			string str = "";
			str = mb.GetMessage(atoi(p[1].c_str()));
			cout << str <<endl;
		}
		else{
			vector<int> numbs = mb.GetNumbers();
			for(vector<int>::iterator it = numbs.begin();it!=numbs.end();it++){
				cout << *it <<": "<< mb.GetMessage(*it) << endl;			}
		}
	}
	return 0;
}

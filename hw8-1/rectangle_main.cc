#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "rectangle.h"
using namespace std;

int main(){
	while(1){
		char line[50];
                char* p[3];
                char* ptr;
                scanf(" %[^\n]",line);
                ptr = strtok(line," ");
                int i=0;
                while (ptr != NULL){
                        p[i] = ptr;
                        ptr = strtok(NULL, " ");
                        i++;
                }

		if (strcmp(p[0],"quit")==0){ 
			break;
		}
		else if(strcmp(p[0],"square")==0){
			Square s(atoi(p[1]));
			s.print();
		}
		else{
			NonSquare ns(atoi(p[1]),atoi(p[2]));
			ns.print();
		}
	}
	return 0;
}
		

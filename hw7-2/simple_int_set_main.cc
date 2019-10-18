#include <iostream>
#include <stdio.h>
#include "simple_int_set.h"
#include <string>
#include <string.h>
#include <stdlib.h>

int main(){
	char a[100];
	set<int> set0,set1,new_set;
	int k;
	set<int>::iterator itr;
	while(1){
		scanf(" %[^\n]",a);
		if(!strcmp(a,"0"))
			break;
		char *b = strtok(a," ");
		k=0;
		set0.clear();
		set1.clear();
		while(b!=NULL){
			if(!strcmp(b,"+"))
				k=1;
			else if(!strcmp(b,"-"))
				k=2;
			else if(!strcmp(b,"*"))
				k=3;
			else if(strcmp(b,"{") && strcmp(b,"}")){
				if(!k)
					set0.insert(atoi(b));
				else
					set1.insert(atoi(b));
			}
			b = strtok(NULL," ");
		}
		if(k==1)
			new_set = SetUnion(set0,set1);
		else if(k==2)
			new_set = SetDifference(set0,set1);
		else
			new_set = SetIntersection(set0,set1);
		cout << "{ ";
		for(itr = new_set.begin();itr != new_set.end();itr++)
			cout << *itr << " ";
		cout << "}\n";
	}		
	
	return 0;
} 

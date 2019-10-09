#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"
#include <string.h>
int main(int argc, char** argv){
	int num = atoi(argv[1]);
	if (num<3 || num%2 == 0)
		return 0;
	int** p = new int*[num];
	for(int i=0;i<num; i++){
		p[i] = new int[num];
	}
	magicsquare(p,num);
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++)
			printf("%d\t",*(*(p+i)+j));
		printf("\n");
	}
	for(int i=0;i<num;++i){
		delete [] p[i];
	}
	delete[] p;
	return 0;
}

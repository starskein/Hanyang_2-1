#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "number.h"

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
		if (strcmp(p[0],"quit")==0) break;
		else if (strcmp(p[0],"number")==0){
			Number num;
			num.setNumber(atoi(p[1]));
			printf("getNumber(): %d\n",num.getNumber());
		}
		else if (strcmp(p[0],"square")==0){
			Square sq;
			sq.setNumber(atoi(p[1]));
			printf("getNumber(): %d\n",sq.getNumber());
			printf("getSquare(): %d\n",sq.getSquare());
		}
		else{
			Cube cube;
                        cube.setNumber(atoi(p[1]));
			printf("getNumber(): %d\n",cube.getNumber());
			printf("getSquare(): %d\n",cube.getSquare());
                        printf("getCube(): %d\n",cube.getCube());
		}
	}
	return 0;
}


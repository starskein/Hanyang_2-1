#include "sort.h"

void sort(int* p,int num){
	for(int i=0;i<num-1;i++){
		for(int j=0;j<num-1-i;j++){
			if(*(p+j)>*(p+j+1)){
				int temp = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = temp;
			}
		}
	}
}
			
	

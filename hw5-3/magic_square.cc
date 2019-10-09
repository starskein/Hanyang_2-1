#include "magic_square.h"

void magicsquare(int** p,int num){
	int mid = num/2;
	int i=0,j=mid;
	for(int k=1;k<=num*num;k++){
		*(*(p+i)+j)=k;
		if(k%num==0)
			i++;
		else{
			i--;
			j++;
		}
		if(i<0)
			i=num-1;
		if(j>num-1)
			j=0;
		
	}
}

#include <stdio.h>

void rotateLeft(int* pa,int* pb,int* pc){
	int temp = *pa;
	*pa = *pb;
	*pb = *pc;
	*pc = temp;
	return;
}
void rotateRight(int* pa,int* pb,int* pc){
	int temp = *pa;
	*pa = *pc;
	*pc = *pb;
	*pb = temp;
	return;
}

int main(){
	int a=10,b=20,c=30;
	int input_num;
	printf("%d %d %d\n", a,b,c);
	scanf("%d",&input_num);
	while(input_num==1 || input_num==2){
		if (input_num==1){
			rotateLeft(&a,&b,&c);
			printf("%d %d %d\n",a,b,c);
		}
		else{
			rotateRight(&a,&b,&c);
			printf("%d %d %d\n",a,b,c);
		}
		scanf("%d",&input_num);
	}

	return 0;	
}

#include <stdio.h>

void getSumDiff(int a, int b, int* pSum, int* pDiff){
	*pSum = a+b;
	*pDiff = a-b;
	return;
}

int main(){
	int n1,n2;
	scanf("%d",&n1);
	scanf("%d",&n2);
	int sum,diff;
	getSumDiff(n1,n2,&sum,&diff);
	printf("Sum: %d\n", sum);
	printf("Diff: %d\n", diff);
	return 0;
}

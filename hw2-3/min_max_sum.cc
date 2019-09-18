#include <stdio.h>

int main(){
	int arr[5];
	for(int i=0; i<5;i++){
		scanf("%d",arr+i);
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	int sum=0;
	for(int i=0;i<5;i++)
		sum=sum+arr[i];
	printf("min: %d\n",arr[0]);
	printf("max: %d\n",arr[4]);
	printf("sum: %d\n",sum);
	return 0;
} 

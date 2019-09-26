#include <stdio.h>

int main(){
	int arr[3][2];
	for (int i=0;i<3;i++){
		for (int j=0;j<2;j++)
			scanf("%d",&arr[i][j]);
	}
	for (int i=0;i<3;i++){
                for (int j=0;j<2;j++)
                        printf("%d ",arr[i][j]);
		printf("\n");
	}
	for (int i=0;i<3;i++)
		printf("%d row`s number sum : %d\n",i+1,arr[i][0]+arr[i][1]);
	
	return 0;
}

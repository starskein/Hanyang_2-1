#include <stdio.h>

typedef struct{
	char name[7];
	int score;
}Person;

void printScoreStars(Person* persons,int len){
	for(int i=0;i<len;i++){
		int temp=persons[i].score/5;
		printf("%s ",persons[i].name);
		for(int j=0;j<temp;j++)
			printf("*");
		printf("\n");
	}
}

int main(void){
	Person persons[3];
	for(int i=0;i<3;i++)
		scanf("%s %d",persons[i].name,&persons[i].score);
	printScoreStars(persons,3);
}




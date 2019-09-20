#include <stdio.h>

typedef struct{
	int xpos;
	int ypos;
}Point;

void scale2x(Point* pp){
	pp->xpos *= 2;
	pp->ypos *= 2;
}

int main(){
	Point persons[3];
	for (int i=0;i<3;i++){
		scanf("%d %d",&persons[i].xpos,&persons[i].ypos);
		scale2x(&persons[i]);
	}
	for(int i=0;i<3;i++)
		printf("[%d] %d %d\n",i, persons[i].xpos,persons[i].ypos);
	
}


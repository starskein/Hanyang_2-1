#include <stdio.h>

typedef struct{
	int xpos;
	int ypos;
}Point;

Point getScale2xPoint(const Point* p){
	Point p2;
	p2.xpos = 2*(p->xpos);
	p2.ypos = 2*(p->ypos);
	return p2;
}

void swapPoint(Point& p1,Point& p2){
	int temp1=p1.xpos;
	int temp2=p1.ypos;
	p1.xpos = p2.xpos;
	p1.ypos = p2.ypos;
	p2.xpos = temp1;
	p2.ypos = temp2;
	return;	
}

int main(void){
	Point p1;
	scanf("%d %d",&p1.xpos,&p1.ypos);
	Point p2 = getScale2xPoint(&p1);
	printf("Calling getScale2cPoint()\n");
	printf("P1 : %d %d\n",p1.xpos,p1.ypos);
	printf("P2 : %d %d\n",p2.xpos,p2.ypos);
	swapPoint(p1,p2);
	printf("Calling swapPoint()\n");
	printf("P1 : %d %d\n",p1.xpos,p1.ypos);
        printf("P2 : %d %d\n",p2.xpos,p2.ypos);
	return 0;
}

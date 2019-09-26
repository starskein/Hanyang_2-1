#include <stdio.h>

typedef struct{
	double x;
	double y;
}Point;

typedef struct{
	char name[7];
	Point points[3];
}Person;

int main(){
	Person p1,p2,p3;
	scanf("%s",p1.name);
	for (int j=0;j<3;j++){
		scanf("%lf %lf",&p1.points[j].x,&p1.points[j].y);
	}
	scanf("%s",p2.name);
	for (int j=0;j<3;j++){
		scanf("%lf %lf",&p2.points[j].x,&p2.points[j].y);
        }
	scanf("%s",p3.name);
	for (int j=0;j<3;j++){
		scanf("%lf %lf",&p3.points[j].x,&p3.points[j].y);
	}


	Point max1,max2,max3;
	for (int i=0;i<3;i++){
		int max=(p1.points[0].x)*(p1.points[0].x) + (p1.points[i].y)*(p1.points[i].y);
		max1=p1.points[0];
		int temp = (p1.points[i].x)*(p1.points[i].x) + (p1.points[i].y)*(p1.points[i].y);
		if (max < temp){
			max = temp;
			max1 = p1.points[i];
		}
	}
	for (int i=0;i<3;i++){
                int max=(p2.points[0].x)*(p2.points[0].x) + (p2.points[i].y)*(p2.points[i].y);
		max2 = p2.points[0];
                int temp = (p2.points[i].x)*(p2.points[i].x) + (p2.points[i].y)*(p2.points[i].y);
                if (max < temp){
                        max = temp;
			max2 = p2.points[i];
		}
        }
	for (int i=0;i<3;i++){
                int max=(p3.points[0].x)*(p3.points[0].x) + (p3.points[i].y)*(p3.points[i].y);
		max3 = p3.points[0];
                int temp = (p3.points[i].x)*(p3.points[i].x) + (p3.points[i].y)*(p3.points[i].y);
                if (max < temp){
                        max = temp;
			max3 = p3.points[i];
		}
        }
	printf("%s (%lf, %lf)\n",p1.name,max1.x,max1.y);
	printf("%s (%lf, %lf)\n",p2.name,max2.x,max2.y);
	printf("%s (%lf, %lf)\n",p3.name,max3.x,max3.y);
	return 0;
	
}

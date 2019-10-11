#include <iostream>
#include <stdio.h>
#include "simple_shape.h"

int main(void){
	char shape;
	float a,b,c,d;
	float area,perimeter;
	while(1){
		printf("shape?\n");
        	scanf("\n%c",&shape);
		if(shape=='Q')
			break;
		if(shape=='C'){
			scanf("%f %f %f",&a,&b,&c);
			Circle circle(a,b,c);
			circle.Cal(area,perimeter);
			printf("area: %f, perimeter: %f\n",area,perimeter);
		}
		else{
			scanf("%f %f %f %f",&a,&b,&c,&d);
			Rect rect(a,b,c,d);
			rect.Cal(area,perimeter);
			printf("area: %f, perimeter: %f\n",area,perimeter);
		//printf("shape?\n");
        	//scanf("\n%c",&shape);
		}
	}
	return 0;
}

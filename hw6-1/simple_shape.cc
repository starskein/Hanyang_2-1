#include "simple_shape.h"
#define PI 3.14
Circle::Circle(float a,float b,float c){
	cen_x=a;
	cen_y=b;
	radius=c;
}
void Circle::Cal(float& area,float& perimeter){
	area = radius*radius*PI;
	perimeter = 2*radius*PI;
	return;
}
Rect::Rect(float a,float b,float c,float d){
	top_x=a;
	top_y=b;
	bot_x=c;
	bot_y=d;
}
void Rect::Cal(float& area,float& perimeter){
	area = (bot_x-top_x)*(top_y-bot_y);
	perimeter = 2*(bot_x-top_x+top_y-bot_y);
}
	

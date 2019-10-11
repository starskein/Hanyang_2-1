#ifndef __SIMPLE_SHAPE__
#define __SIMPLE_SPAPE__
//class Circle;
//class Rect;
class Circle{
	float cen_x;
	float cen_y;
	float radius;
public:
	Circle(float a,float b,float c);
	void Cal(float& area,float& perimeter);
};
class Rect{
	float top_x;
	float top_y;
	float bot_x;
	float bot_y;
public:
	Rect(float a,float b,float c,float d);
	void Cal(float& area,float& perimeter);
};
#endif

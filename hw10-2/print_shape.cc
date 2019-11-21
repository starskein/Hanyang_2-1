
#include "print_shape.h"
#define PI 3.14
double Shape::getArea(){}
double Shape::getPerimeter(){}
string Shape::getTypeString(){}

Circle::Circle(double radius){
	r = radius;
}
double Circle::getArea(){
	return PI*r*r;
}
double Circle::getPerimeter(){
	return 2*PI*r;
}
string Circle::getTypeString(){
	return "Circle";
}
Rectangle::Rectangle(double width, double height){
	w=width;
	h=height;
}
double Rectangle::getArea(){
        return w*h;
}
double Rectangle::getPerimeter(){
        return 2*(w+h);
}
string Rectangle::getTypeString(){
        return "Rectangle";
}

	

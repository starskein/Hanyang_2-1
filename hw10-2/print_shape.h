#pragma once
#include <string>
#include <iostream>
using namespace std;

class Shape{
	public:
		virtual double getArea();
		virtual double getPerimeter();
		virtual string getTypeString();
		
};
class Circle:public Shape{
	public:
		Circle(double);
		virtual double getArea();
                virtual double getPerimeter();
                virtual string getTypeString();
	
	private:
		double r;
};
class Rectangle:public Shape{
	public:
		Rectangle(double,double);
		virtual double getArea();
                virtual double getPerimeter();
                virtual string getTypeString();

	private:
		double w;
		double h;
};


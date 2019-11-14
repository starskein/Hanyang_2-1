class Shape{
	public:
		Shape(double,double);
		virtual double getArea();
	protected:
		double w;
		double h;
	
};
class Triangle:public Shape{
	public:
		Triangle(double,double);
		double getArea();
};

class Rectangle:public Shape{
	public:
		Rectangle(double,double);
		double getArea();
};

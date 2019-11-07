class Shape{
	public:
		Shape();
		Shape(int x,int y,int width,int height,char p_);
		double GetArea();
		int GetPerimeter();
		void Draw(int canvas_width,int canvas_height);
	protected:
		int x_;
		int y_;
		int w;
		int h;
		char p;
};
class Square : public Shape{
	public:
		Square(int,int,int,char);
};
class Rectangle : public Shape{
	public:
		Rectangle(int,int,int,int,char);
};
class Diamond : public Shape{
	public:
		Diamond(int,int,int,char);
		double GetArea();
		double GetPerimeter();
		void Draw(int canvas_width, int canvas_height);
};


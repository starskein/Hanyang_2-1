class Canvas{
	public:
		Canvas(int row,int col);
		~Canvas();
		void Resize(int w, int h);
		bool DrawPixel(int x,int y,char brush);
		void Print();
		void Clear();
	private:
		int r;
		int c;
		char arr[1005][1005];

};
class Shape{
	public:
		Shape(int, int, int, int, char);
 		virtual ~Shape();
		virtual void Draw(Canvas* canvas);
		virtual void PrintInfo();
	protected:
		int width;
		int height;
		int x;
		int y;
		int brush;
};
class Rectangle : public Shape{
	public:
		Rectangle(int, int, int, int, char);
		virtual void Draw(Canvas* canvas);
		void PrintInfo();
};
class UpTriangle : public Shape{
	public:
		UpTriangle(int, int , int, char);
		virtual void Draw(Canvas* canvas);
		void PrintInfo();
};
class DownTriangle : public Shape{
	public:
		DownTriangle(int, int, int, char);
		virtual void Draw(Canvas* canvas);
		void PrintInfo();
};
class Diamond : public Shape{
	public:
		Diamond(int,int,int,char);
		virtual void Draw(Canvas* canvas);
		void PrintInfo();
};

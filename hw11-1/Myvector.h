#include <iostream>
using namespace std;
class MyVector{
	private:
		int len;
		int* arr;
	public:
		MyVector(int l);
		~MyVector();
		void SetArr(int* ar);
		void AddArr(int* ar);
		void MinArr(int* ar);
		void AddArr(int ar);
                void MinArr(int ar);
		void PrintArr();
		MyVector operator+(const MyVector& a);
		MyVector operator-(const MyVector& a);
		MyVector operator+(const int a);
		MyVector operator-(const int a);
	
};

#include <iostream>
using namespace std;

class MyString{
	private:
		int len;
		char* arr;
	public:
		MyString();
		MyString operator+(const MyString& a);
		MyString operator*(const int a);
		friend ostream& operator<<(ostream& out, const MyString& b);
		friend istream& operator>>(istream& in, MyString& b);
};

#include <iostream>
#include <string.h>
#include "MyString.h"

MyString::MyString():len(0),arr(new char[1005]){
	arr[0] = '\0';
}
MyString MyString::operator+(const MyString& a){
	MyString c;
	strcat(c.arr, arr);
	strcat(c.arr,a.arr);
	return c;
}

MyString MyString::operator*(const int a){
	MyString c;
	for(int i=0; i<a; i++)
		strcat(c.arr,arr);
	return c;
}
ostream& operator<<(ostream& out, const MyString& b){
	out << b.arr;
	return out;
}
istream& operator>>(istream& in, MyString& b){
	in >> b.arr;
	return in;
}

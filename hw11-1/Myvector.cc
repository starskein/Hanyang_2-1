#include "Myvector.h"
MyVector::MyVector(int l){
	len = l;
	arr = new int[len];
}
MyVector::~MyVector(){
	delete[] arr;
}
void MyVector::PrintArr(){
	for(int i=0;i<len;i++)
		cout << arr[i] << " ";
	cout << endl;
}

void MyVector::SetArr(int* ar){
	for(int i=0;i<len;i++){
		arr[i] = ar[i];
	}
}
void MyVector::AddArr(int* ar){
	for(int i=0;i<len;i++){
		arr[i] += ar[i];
	}
}
void MyVector::MinArr(int* ar){
        for(int i=0;i<len;i++){
                arr[i] -= ar[i];
        }
}
void MyVector::AddArr(int ar){
        for(int i=0;i<len;i++){
                arr[i] += ar;
        }
}
void MyVector::MinArr(int  ar){
        for(int i=0;i<len;i++){
                arr[i] -= ar;
        }
}

MyVector MyVector::operator+(const MyVector& a){
	MyVector new_vec(len);
	new_vec.SetArr(arr);
	new_vec.AddArr(a.arr);
	return new_vec;
}
MyVector MyVector::operator-(const MyVector& a){
        MyVector new_vec(len);
        new_vec.SetArr(arr);
        new_vec.MinArr(a.arr);
        return new_vec;
}
MyVector MyVector::operator+(const int a){
        MyVector new_vec(len);
        new_vec.SetArr(arr);
        new_vec.AddArr(a);
        return new_vec;
}
MyVector MyVector::operator-(const int a){
        MyVector new_vec(len);
        new_vec.SetArr(arr);
        new_vec.MinArr(a);
        return new_vec;
}

	

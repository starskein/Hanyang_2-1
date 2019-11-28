#include "MyVector.h"
#include "MyContainer.h"
#include "MyContainer.cc"
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
MyVector<T>::MyVector()
	:MyContainer<T>()
{
	capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(int n)
	:MyContainer<T>(n)
{
	capacity = n;
}

template <typename T>
MyVector<T>::MyVector(T* arr, int n)
	:MyContainer<T>(arr, n)
{
	capacity = this->n_ele;
}

template <typename T>
bool MyVector<T>::empty() const
{
	if(this->n_ele == 0) return 1;
	return 0;
}

template <typename T>
int MyVector<T>::size() const
{
	return this->n_ele;
}

template <typename T>
int MyVector<T>::max_size() const
{
	return capacity;
}

template <typename T>
void MyVector<T>::reserve(int new_cap)
{
	T* temp = this->obj_arr;
	capacity += new_cap;
	this->obj_arr = new T[capacity];
	for(int i=0;i<this->n_ele;i++) this->obj_arr[i] = temp[i];
}

template <typename T>
void MyVector<T>::push_back(T obj)
{
	if (this->n_ele == capacity) reserve(this->n_ele);
	this->n_ele++;
	this->obj_arr[this->n_ele-1] = obj;
}

template <typename T>
void MyVector<T>::pop_back()
{
	T* temp = this->obj_arr;
	capacity--;
	this->n_ele--;
	this->obj_arr = new T[capacity];
	for(int i=0;i<capacity;i++) this->obj_arr[i] = temp[i];
}

template <typename T>
T& MyVector<T>::front() const
{
	return (this->obj_arr[0]);
}

template <typename T>
T& MyVector<T>::back() const
{
	
	return (this->obj_arr[this->n_ele-1]);
}
	
template <typename T>
T& MyVector<T>::at(int idx) const
{

	return this->obj_arr[idx];
}

template <typename T>
T& MyVector<T>::operator[](const int& i) const
{
	return at(i);
}

template <typename T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs) 
{
	int h = this->n_ele+rhs.size();
	int w = h - rhs.size();
	T* arr = new T[h];
	int i;
	for(i = 0;i<this->n_ele;i++) 
		arr[i] = this->obj_arr[i];
	for(;i<h;i++)
		arr[i] = rhs[i-w];
	
	
	MyVector<T> new_t(arr,h);
	return new_t;
}

#include "MyContainer.h"
#include <iostream>


template <typename T>
MyContainer<T>::MyContainer()
{
	n_ele = 0;
}

template <typename T>
MyContainer<T>::MyContainer(int n)
{
	obj_arr = new T[n];
	n_ele = n;
}

template <typename T>
MyContainer<T>::MyContainer(T* arr, int n)
{
	obj_arr = arr;
	n_ele = n;
}


template <typename T>
MyContainer<T>::~MyContainer()
{
	delete[] obj_arr;
}

template <typename T>
void MyContainer<T>::clear()
{
	n_ele = 0;
}

template <typename T>
int MyContainer<T>::size()
{
	return n_ele;
}

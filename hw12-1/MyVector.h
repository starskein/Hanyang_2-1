#ifndef __MVE_H_
#define __MVE_H_

#include "MyContainer.h"

template <typename T>
class MyVector : public MyContainer<T>
{
	private:
		int capacity;

	public:
		MyVector();
		MyVector(int n);
		MyVector(T* arr, int n);
		bool empty() const;
		int size() const;
		int max_size() const;
		void reserve(int new_cap);
		void push_back(T obj);
		void pop_back();
		T& front() const;
		T& back() const;
		T& at(int idx) const;
		T& operator[](const int& i) const;
		MyVector<T> operator+(const MyVector<T>& rhs);
};

#endif

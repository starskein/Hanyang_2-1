#ifndef __MC_H_
#define __MC_H_

template <typename T>
class MyContainer
{
	protected:
		T* obj_arr;
		int n_ele;

	public:
		MyContainer();
		MyContainer(int n);
		MyContainer(T* arr, int n);
		~MyContainer();
		void clear();
		int size();
};

#endif

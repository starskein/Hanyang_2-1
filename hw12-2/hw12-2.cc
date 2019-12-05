#include<iostream>

using namespace std;


template <class T>
class My_shared_ptr
{
	private:
		T* m_obj;
		int* count;
	public:
		My_shared_ptr():m_obj(NULL),count(NULL)
		{
			//
		}
		
		My_shared_ptr(T* obj):m_obj(obj),count(new int(1))
		{
			//
		}
		
		My_shared_ptr(const My_shared_ptr& rhs)//copy constructor.
		{
			m_obj = rhs.m_obj;
			count = rhs.count;
			increase();
			//
		}
		
		~My_shared_ptr()
		{
			decrease();
			if(getCount() == 0){
				cout << "everything destroyed"<<endl;
				delete m_obj;
				delete count;
			}	
			//
		}
		
		My_shared_ptr<T>& operator=(const My_shared_ptr<T>& rhs)
		{
			m_obj = rhs.m_obj;
			count = rhs.count;
			increase();
			//
			return *this;
		}
	

		int getCount(){
			if(count == NULL) return 0;
			return *count;
			//
		}
		
		void increase(){
			(*count)++;
			//
		}
		void decrease(){
			(*count)--;
			//
		}
		
		const T* get_m_obj()
		{
			return m_obj;
		}
};

typedef unsigned long T;
int main()
{
	{		
		My_shared_ptr<T> a;
		cout<<a.getCount()<<endl;
		{
			My_shared_ptr<T> b(new T(5));
			cout<<a.getCount()<<endl;
			cout<<b.getCount()<<endl;
			
			if(a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;
			
			a = b;//assignment operation
			cout<<a.getCount()<<endl;
			cout<<b.getCount()<<endl;
			
			if(a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;
		}
		cout<<a.getCount()<<endl;
	}
	return 0;
}

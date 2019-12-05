#include <iostream>
using namespace std;
class A{
	public:
		A(){}
		A(const A& a){}
		~A(){}
};
int main() {
	try{
		try{
			A a;
			throw a;
		}
		catch(A &a)
		{
			#if 1//rethrow, 아래 throw twice구문도 실행시켜 볼  것
			//	cout << "rethrow" << endl;
			//	throw;
				cout << "throw twice" << endl;
                                throw a;

			#else//throw twice	
				cout << "throw twice" << endl;
				throw a;
			#endif
		}
	}	
	catch(A &a)
	{
		cout << "exception handled" << endl;
	}
	
	return 0;
}

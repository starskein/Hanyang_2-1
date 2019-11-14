#include <string>
using namespace std;

class Animal{
	public:
		Animal(string,int);
		virtual void printInfo();
	protected:
		string name;
		int age;
};
class Zebra : public Animal{
	public:
		Zebra(string,int,int);
		virtual void printInfo();
	private:
		int numStripes;
};
class Cat : public Animal{
	public:
		Cat(string,int,string);
		virtual void printInfo();
	private:
		string favoriteToy;
};


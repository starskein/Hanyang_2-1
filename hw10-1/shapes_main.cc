#include <iostream>
#include <vector>
#include "shapes.h"
using namespace std;

int main(){
	vector<Shape*> vec;
	double a,b,c,d;
	cin >> a >> b;
	cin >> c >> d;
	Triangle* t = new Triangle(a,b);
	Rectangle* r = new Rectangle(c,d);
	vec.push_back(t);
	vec.push_back(r);
	cout << vec[0]->getArea() << endl;
	cout << vec[1]->getArea() << endl;
	delete vec[0];
	delete vec[1];
	return 0;
}

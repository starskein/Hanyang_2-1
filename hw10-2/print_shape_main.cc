#include "print_shape.h"
#include <vector>
int main(){
	vector<Shape*> shapes;
	while(1){
		string str;
		double a,b;
		cin >> str;
		if(str=="0") break;
		else if(str=="c"){
			cin >> a;
			Circle* c = new Circle(a);
			shapes.push_back(c);
		}
		else{
			cin >> a >> b;
			Rectangle* r = new Rectangle(a,b);
			shapes.push_back(r);
		}
	}
	for(vector<Shape*>::iterator itr=shapes.begin();itr!=shapes.end();itr++)
		cout << (*itr)->getTypeString() << ", " << (*itr)->getArea() << ", " << (*itr)->getPerimeter() << endl;
	for(vector<Shape*>::iterator itr=shapes.begin();itr!=shapes.end();itr++)
		delete *itr;
	return 0;
}

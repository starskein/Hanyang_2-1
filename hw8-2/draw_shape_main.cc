#include <iostream>
#include <string>
#include "draw_shape.h"
using namespace std;

int main(){
	Shape s;
	int n,m;
	string str;
	int a,b;
	int c,d;
	char e;
	cin >> n >> m;
	while(1){
		cin >> str;
		if(str=="quit") break;
		else if (str=="rect"){
			cin >> a >> b >> c >> d >> e;
			Rectangle re(a,b,c,d,e);
			cout << "Area: " << re.GetArea() << endl;
			cout << "Perimeter: " << re.GetPerimeter() << endl;
			re.Draw(n,m);
		}
		else if (str=="square"){
                        cin >> a >> b >> c >>  e;
                        Square sq(a,b,c,e);
                        cout << "Area: " << sq.GetArea() << endl;
                        cout << "Perimeter: " << sq.GetPerimeter() << endl;
                        sq.Draw(n,m);
                }
		else if (str=="diamond"){
                        cin >> a >> b >> c >> e;
                        Diamond di(a,b,c,e);
                        cout << "Area: " << di.GetArea() << endl;
                        cout << "Perimeter: " << di.GetPerimeter() << endl;
                        di.Draw(n,m);
                }
	}
}



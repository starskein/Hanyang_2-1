#include <iostream>
#include "circle.h"
using namespace std;
int main(void){
	double radius;
	double perimeter,area;
	cin >> radius;
	perimeter = getCirclePerimeter(radius);
	area = getCircleArea(radius);
	cout << "Perimeter: " << perimeter << endl;
	cout << "Area: " << area << endl;
	return 0;
}

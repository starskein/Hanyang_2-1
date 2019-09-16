#include <iostream>
#include <string.h>
using namespace std;

struct Person {
	char name[20];
	int age;
}s,*p;

int main(void){
	p = &s;
	char n1[20],n2[20],n3[20];
	int g1,g2,g3;

	cout << "Name: ";
	cin >> n1;
	cout << "Age: ";
	cin >> g1;
	cout << "Name: ";
        cin >> n2;
        cout << "Age: ";
        cin >> g2;
	cout << "Name: ";
        cin >> n3;
        cout << "Age: ";
        cin >> g3;


	strcpy(p->name,n1);
	p->age = g1;
	cout << "Name: " << p->name<< endl;
	cout << "Age: " << p->age<< endl;
	strcpy(p->name,n2);
        p->age = g2;
        cout << "Name: " << p->name<< endl;
        cout << "Age: " << p->age<< endl;
	strcpy(p->name,n3);
        p->age = g3;
        cout << "Name: " << p->name<< endl;
        cout << "Age: " << p->age<< endl;
}

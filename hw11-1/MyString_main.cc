#include <stdio.h>
#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

int main() {
	string s,op,s2;
	int n;
	MyString a;
	MyString b;

	while (1) {
		cin >> s;
		if (s == "new") {
			cout << "enter a\n";
			cin >> a;
			cout << "enter b\n";
			cin >> b;

			
		}
		else if (s == "quit") return 0;
		else {
			cin >> op;

			if (op == "+") {
				cin >> s2;
				if (s == "a") {
					if (s2 == "a") {
						MyString c = a.operator+(a);
						cout << c << endl;
					}
					else {
						MyString c = a.operator+(b);
						cout << c << endl;
					}
				}
				else {
					if (s2 == "a") {
						MyString c = b.operator+(a);
						cout << c << endl;
					}
					else {
						MyString c = b.operator+(b);
						cout << c << endl;
					}
				}
			}
			else if (op == "*") {
				cin >> n;
				if (s == "a") {
					MyString c = a.operator*(n);
					cout << c << endl;
				}
				else {
					MyString c = b.operator*(n);
					cout << c << endl;
				}
			}
		}

	}

	return 0;
}

#include <iostream>
#include "Animals.h"
using namespace std;

Animal::Animal(string str, int n){
	name = str;
	age = n;
}
void Animal::printInfo(){
}
Zebra::Zebra(string str, int n, int m) : Animal(str,n){
	numStripes = m;
}
void Zebra::printInfo(){
	cout << "Zebra, Name: " << name << ", ";
	cout << "Age: " << age << ", ";	
	cout << "Number of stripes: " << numStripes << endl;
}
Cat::Cat(string str, int n, string str2) : Animal(str,n){
	favoriteToy = str2;
}
void Cat::printInfo(){
	cout << "Cat, Name: " << name << ", ";
        cout << "Age: " << age << ", ";   
        cout << "Favorite toy: " << favoriteToy << endl;
}



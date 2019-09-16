#include <iostream>
#include <string.h>
using namespace std;

struct Person{
	char name[50];
	int age;
}AA;
int main(void){
	strcpy(AA.name,"david");
	AA.age = 20;
	cout <<"name: " << AA.name << endl;
	cout <<"age: " << AA.age << endl;
}

 

#include <iostream>

typedef struct{
	char name[10];
	int age;
}Person;

int main(void){
	int n;
	std::cin >> n;
	Person* p = new Person[n];
	for (int i=0;i<n;i++){
		std::cin >> p[i].name;
		std::cin >> p[i].age;
	}
	for (int i=0;i<n;i++){
                std::cout <<"Name: "<< p[i].name;
                std::cout <<" Age: " << p[i].age << std::endl;
        }

	delete []p;
	return 0;
}

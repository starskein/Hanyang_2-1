#include <iostream>
#include <string>

int add(int a, int b);
std::string add(std::string a,std::string b);

int main(void){
	int a,b;
	std::string c,d;
	std::cin >> a >> b;
	std::cin >> c >> d;
	int sum1 = add(a,b);
	std::string sum2 = add(c,d);
	std::cout << sum1 << std::endl;
	std::cout << sum2 << std::endl;
	return 0;
}

int add(int a, int b){
	return a+b;
}
std::string add(std::string a, std::string b){
	return a+"-"+b;
}
	

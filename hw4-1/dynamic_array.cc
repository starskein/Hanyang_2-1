#include <iostream>

int main(void){
	int n;
	std::cin >>n;
	int* p = new int[n];
	for(int i=0;i<n;i++)
		*(p+i) = i;
	for (int i=0;i<n;i++)
		std::cout << *(p+i) << " ";
	std::cout << std::endl;
	delete [] p;
	return 0;
}

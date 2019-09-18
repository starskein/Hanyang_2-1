#include <iostream>
using namespace std;
int main(){
	double arr[5] = {1.1,2.2,3.3,4.4,5.5};
	double* parr = arr;
	for(int i=0;i<5;i++){
		*(parr+i) = *(parr+i)+*(parr+i);
	}
	for(int i=0;i<5;i++){
		cout << *(parr+i) <<endl;
	}
}

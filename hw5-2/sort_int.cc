#include <iostream>
#include "sort.h"
using namespace std;
int main(void){
	int num;
	cin >> num;
	if (num <= 0)
		return 0;
	int* p = new int[num];
	for(int i=0; i<num; i++)
                cin >> *(p+i);
	sort(p,num);
	for (int i=0;i<num;i++)
		cout << *(p+i) <<" " ; 
	cout << endl;
	delete[] p;
}

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, char** argv){
	int sum=0;
	char* stsum = new char[200];
	for (int i = 1; i < argc; ++i){
		if(atoi(argv[i])==0)
			strcat(stsum,argv[i]);
		else
			sum += atoi(argv[i]);
	}
	cout << stsum << endl;
	cout << sum << endl;
	
	delete[] stsum;
}
			
	

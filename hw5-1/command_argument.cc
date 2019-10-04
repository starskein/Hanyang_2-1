#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main(int argc, char** argv){
	int num = atoi(argv[2]);
	for(int i=0;i<num;i++)
		cout << argv[1] << endl;
	return 0;
}
	

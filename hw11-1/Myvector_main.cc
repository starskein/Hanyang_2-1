#include "Myvector.h"
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	string str;
	int n;
	cin >> str >> n;
	int* arr = new int[n];
	int* arr2 = new int[n];
	cout << "enter a" << endl;
	for(int i=0;i<n; i++){
		cin >> arr[i];
	}
	cout << "enter b" << endl;
        for(int i=0;i<n; i++){
                cin >> arr2[i];
        }
	MyVector a(n);
	MyVector b(n);
	a.SetArr(arr);
	b.SetArr(arr2);
	MyVector result(n);
	while(1){
		string s,k,l;
		
		cin >> s;
		if (s=="quit") break;
		cin >> l >> k;
		if(s=="a"){
			//cout << "work\n";
			if(l=="+"){
				//cout << "also work\n";
				if(k=="b"){
					//cout << "working\n";
					(a+b).PrintArr();
					//cout << "problem here?\n";
				}
				else if(k=="a"){
					(a+a).PrintArr();
				}
				else{	
					(a+atoi(k.c_str())).PrintArr();
				
				}
			}
			 if(l=="-"){
                                //cout << "also work\n";
                                if(k=="b"){
                                        //cout << "working\n";
                                        (a-b).PrintArr();
                                        //cout << "problem here?\n";
                                }
                                else if(k=="a"){
                                        (a-a).PrintArr();
                                }
                                else{
                                        (a-atoi(k.c_str())).PrintArr();

                                }
                        }

		}
		 if(s=="b"){
                        if(l=="+"){
                               if(k=="b"){
                                        (b+b).PrintArr();
                              
                                }
                                else if(k=="a"){
                                       	(b+a).PrintArr();
				}
                                else{
                                        (b+atoi(k.c_str())).PrintArr();
                                }
			}
			if(l=="-"){
                               if(k=="b"){
                                        (b-b).PrintArr();

                                }
                                else if(k=="a"){
                                        (b-a).PrintArr();
                                }
                                else{
                                        (b-atoi(k.c_str())).PrintArr();
                                }
                        }

		}
		
	}
	delete[] arr;
	delete[] arr2;
	
}
	

					
						

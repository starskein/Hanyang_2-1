#include <vector>
#include "dynamic_cast.h"
using namespace std;

int main(){
	vector<B*> vec;
        while(1){

                string str;
                cin >> str;
                if(str =="0") break;
		else if(str =="B"){
			B* b = new B;
			vec.push_back(b);
		}
                else if(str =="C"){
                        C* c = new C;
                        vec.push_back(c);
                }
                else{
                        D* d = new D;
			vec.push_back(d);
		}
		
	}
	for(int i=0;i<vec.size();i++){
		C* cp = dynamic_cast<C*>(vec[i]);
		if(cp == NULL){
			D* dp = dynamic_cast<D*>(vec[i]);
			if(dp == NULL){}
			else dp->test_D();
		}
		else
			cp->test_C();
	}
	return 0;
}


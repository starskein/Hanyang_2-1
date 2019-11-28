#include "calendar.h"
#include <string>
#include <stdlib.h>

using namespace std;

int main(){
	Date d;
	while(true){
		string str;
		cin >> str;
		if(str == "quit")
			break;
		if(str == "set"){
			cin >> d;
			//cout << d.GetYear() <<" "<< d.GetMonth() << " " <<d.GetDay()<<endl;
			cout << d<<endl;
		}
		else{
			//cout << d.GetYear() <<" "<< d.GetMonth() << " " <<d.GetDay()<<endl;

			str = str.substr(5);
			if(atoi(str.c_str())==0) d.NextDay(1);
			else d.NextDay(atoi(str.c_str()));
			cout << d<<endl;
			//cout << d.GetYear() <<" "<< d.GetMonth() << " " <<d.GetDay()<<endl;

		}
	}
	return 0;
}	

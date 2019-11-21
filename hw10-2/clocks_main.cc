#include <iostream>
#include <vector>
#include "clocks.h"
using namespace std;

int main(){
	vector<Clock*> vec;
	double x;



	Clock* s = new SundialClock(0,0,0);
	Clock* c = new CuckooClock(0,0,0);
	Clock* g = new GranFatherClock(0,0,0);
	Clock* w = new WristClock(0,0,0);
	Clock* a = new AtomicClock(0,0,0);
	vec.push_back(s);
	vec.push_back(c);
	vec.push_back(g);
	vec.push_back(w);
	vec.push_back(a);
	cin >> x;
	cout <<" Reported clock times after running : \n";
	for (int i=0;i<5;i++){
		vec[i]->reset();
		vec[i]->displayTime();
		for(int j=0;j<x;j++)
			vec[i]->tick();
	}
	cout << "\n Running the clocks...\n\n";
	cout << "Reported clock times after running :\n";
	for(int i=0;i<5;i++){
		vec[i]->displayTime();
		delete vec[i];
	}
	vec.clear();
}

#include "simple_int_set.h"
using namespace std;
set<int> SetIntersection(const set<int>& set0, const set<int>& set1){
	set<int> new_set;
	set<int>::iterator itr0,itr1;
	new_set.clear();
	for(itr0=set0.begin();itr0!=set0.end();itr0++){
                for(itr1=set1.begin();itr1!=set1.end();itr1++){
                        if(*itr0==*itr1)
                                new_set.insert(*itr0);
                }
        }

	return new_set;

}
set<int> SetUnion(const set<int>& set0, const set<int>& set1){
        set<int> new_set;
        set<int>::iterator itr;
	new_set.clear();

	for(itr=set0.begin();itr!=set0.end();itr++)
		new_set.insert(*itr);
	for(itr=set1.begin();itr!=set1.end();itr++)
                new_set.insert(*itr);
	return new_set;
}
set<int> SetDifference(const set<int>& set0, const set<int>& set1){
        set<int> new_set;
        set<int>::iterator itr,itr0,itr1;
	new_set.clear();
	for(itr=set0.begin();itr!=set0.end();itr++)
                new_set.insert(*itr);
	for(itr0=set0.begin();itr0!=set0.end();itr0++){
                for(itr1=set1.begin();itr1!=set1.end();itr1++){
                        if(*itr0==*itr1)
                                new_set.erase(*itr0);
                }
        }
	return new_set;
}


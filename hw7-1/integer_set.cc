#include <vector>
#include <algorithm>
#include <iostream>
#include "integer_set.h"

IntegerSet::IntegerSet(){

}
IntegerSet::~IntegerSet(){

}
void IntegerSet::AddNumber(int num){
	numbers_.push_back(num);
	sort(numbers_.begin(),numbers_.end());
}
void IntegerSet::DeleteNumber(int num){
	int check = 0;
	for(std::vector<int>::iterator itr = numbers_.begin();itr!=numbers_.end();itr++){
		if(num==*itr)
			check++;
	}
	if(check==0){
		 return;
	}
	numbers_.erase(std::remove(numbers_.begin(),numbers_.end(),num),numbers_.end());
}
int IntegerSet::GetItem(int pos) const{
	if (pos > numbers_.end()-numbers_.begin())
		return -1;
	return *(numbers_.begin()+pos);
}
void IntegerSet::Print(){
	for (std::vector<int>::iterator itr = numbers_.begin();itr != numbers_.end();itr++){
	std::cout << *itr << " ";
	}
	std::cout << "\n";
}
			


#include <iostream>
#include <vector>
#include <algorithm>
#include "sorted_array.h"

SortedArray::SortedArray(){

}
SortedArray::~SortedArray(){

}
void SortedArray::AddNumber(int num){
	numbers_.push_back(num);
}
std::vector<int> SortedArray::GetSortedAscending(){
	sort(numbers_.begin(),numbers_.end());
	return numbers_;
}
std::vector<int> SortedArray::GetSortedDescending(){
        sort(numbers_.begin(),numbers_.end(),std::greater<int>());
	return numbers_;
}

	

#include <iostream>
#include <stdlib.h>
#include <string>
#include "sorted_array.h"

int main(void){
	std::string str;
	std::cin >> str;
	SortedArray s_arr;
	while (atoi(str.c_str())!=0){
		s_arr.AddNumber(atoi(str.c_str()));
		std::cin >> str;
	}
	while (str != "quit"){
		if(str == "ascend"){	
			std::vector<int> asc = s_arr.GetSortedAscending();
			for (std::vector<int>::iterator itr = asc.begin();itr!= asc.end();itr++){
				std::cout << *itr << " ";
			}
			std::cout << "\n";
		}
		else if (str == "descend"){
			std::vector<int> des = s_arr.GetSortedDescending();
                        for (std::vector<int>::iterator itr = des.begin();itr!= des.end();itr++){
                                std::cout << *itr << " ";
                	}
			std::cout << "\n";
		}
		else if (str == "max"){
			std::vector<int> des = s_arr.GetSortedDescending();
			std::cout << *(des.begin()) << "\n";
		}
		else if (str == "min"){
                        std::vector<int> asc = s_arr.GetSortedAscending();
                        std::cout << *(asc.begin()) << "\n";
                }
		std::cin >> str;
	}
	return 0;
}

			
		
		
	

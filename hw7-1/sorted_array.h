#include <iostream>
#include <vector>
class SortedArray {
	public:
		SortedArray();
		~SortedArray();
		void AddNumber(int num);
		std::vector<int> GetSortedAscending();
		std::vector<int> GetSortedDescending();
		int GetMax() const;
		int GetMin() const;
	private:
		std::vector<int> numbers_;
};	

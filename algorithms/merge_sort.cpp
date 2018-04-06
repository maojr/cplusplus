#include <vector>
#include <iostream>
#include <algorithm>

template <typename BidirectionalIter>
void merge_sort(BidirectionalIter first, BidirectionalIter last) {
	size_t len = last - first;
	if (len == 0 || len == 1)
		return;
	BidirectionalIter mid = first + len / 2;
	merge_sort(first, mid);
	merge_sort(mid, last);
	std::inplace_merge(first, mid, last);
}

int main() 
{
	std::vector<int> vec = {1, 9, 6, 4, 2, 8};
	merge_sort(vec.begin(), vec.end());
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
	std::cin.get();
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> num = { 1,2,3,4,5 };

	auto maxElement = std::max_element(num.begin(), num.end());
	if (maxElement != num.end()) {
		std::cout << "largest element:" << *maxElement << std::endl;
	}
	auto minElement = std::min_element(num.begin(), num.end());
	if (minElement != num.end()) {
		std::cout << "smallest element:" << *minElement << std::endl;
	}
	return 0; 
}
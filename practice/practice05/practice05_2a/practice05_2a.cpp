#include <iostream>
#include <vector>
#include <numeric>

int main() {
	std::vector<int> num = { 1,2,3,4,5 };

	int sum = std::accumulate(num.begin(), num.end(), 0);
	std::cout << "sum of elements:" << sum << std::endl;

	int product = std::accumulate(num.begin(), num.end(), 1, std::multiplies<int>());
	std::cout << "product of elements:" << product << std::endl;
	return 0;
	
}
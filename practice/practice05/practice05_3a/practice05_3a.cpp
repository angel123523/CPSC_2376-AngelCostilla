#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
	std::vector<int> number;
	int num, n;

	std::cout << "enter the number of integers:";
	std::cin >> n;

	std::cout << "enter" << n << "integers:";
	for (int i = 0;i < n; ++i) {
		std::cin >> num;
		number.push_back(num);
	}
	std::cout << "squared elements:";
	std::for_each(number.begin(), number.end(), [](int x) {
		std::cout << x * x << " ";
		});
	std::cout << std::endl;

	int sum = std::accumulate(number.begin(), number.end(), 0, [](int acc, int x) {
		return acc + x * x;
		});
	std::cout << "sum of the squared elements:" << sum << std::endl;
	return 0;

}

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> number;
	int num, n, threshold;
	std::cout << "enter the number of integers:";
	std::cin >> n;

	std::cout << "enter" << n << "integers:";
	for (int i = 0; i < n;++i) {
		std::cin >> num;
		number.push_back(num);
	}
	std::cout << "enter the threshould value:";
	std::cin >> threshold;

	int count = std::count_if(number.begin(), number.end(), [threshold](int x) {
		return x > threshold;
		});
	std::cout << "numbers of elements greater than the threshold:" << count << std::endl;

	auto new_end = std::remove_if(number.begin(), number.end(), [threshold](int x) {
		return x < threshold;
		});

	number.erase(new_end, number.end());

	std::cout << "modified list after flitering:";
	for (int val : number) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
	return 0;

}
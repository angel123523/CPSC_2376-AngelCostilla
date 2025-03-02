#include <iostream>
#include <vector>
#include <limits>

int main() {
	std::vector<int> numbers;
	int num;

	std::cout << "enter integers: (type end to stop)\n ";
	while (true) {
		std::cout << "enter a number:";
		if (std::cin >> num) {
			numbers.push_back(num);
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}
	std::cout << "you entered these numbers:";
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();++it) {
		std::cout << *it << "";
	}
	std::cout << std::endl;
	int sumEven = 0;
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();++it) {
		if (*it % 2 == 0) {
			sumEven += *it;

		}
	}
	std::cout << "sum of the even numbers:" << sumEven << std::endl;
	return 0;
}
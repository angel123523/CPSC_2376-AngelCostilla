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
	std::cout << "numbers entered in reverse:";
	for (std::vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend();++it) {
		std::cout << *it << "";
	}
	std::cout <<  std::endl;
	return 0;
}
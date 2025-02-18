#include <string>
#include <algorithm>
#include <iostream>

template <typename T>
T findMax(T a, T b, T c) {
	return std::max(a, std::max(b, c));
}
int main() {
	int choice;
	std::cout << "compare  numbers(1) or  words(2)";
	std::cin >> choice;

	if (choice == 1) {
		int num1, num2, num3;
		std::cout << "enter first value:";
		std::cin >> num1;
		std::cout << "enter second value:";
		std::cin >> num2;
		std::cout << "enter third value:";
		std::cin >> num3;

		int maxValue = findMax(num1, num2, num3);
			std::cout << "max value:" << maxValue << std::endl;
	}
	else if (choice == 2) {
		std::string str1, str2, str3;
		std::cout << "enter first value:";
		std::cin >> str1;
		std::cout << "enter second value:";
		std::cin >> str2;
		std::cout << "enter third value:";
		std::cin >> str3;
		
		std::string maxValue = findMax(str1, str2, str3);
		std::cout << "Max value:" << maxValue << std::endl;
	}
	else {
		std::cout << "invalid choice." << std::endl;
	}
	return 0;
}

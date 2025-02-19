#include <iostream>
#include <string>

template <typename T>
T findMax(T a, T b, T c) {
	if (a >= b && a >= c) {
		return a;
	}
	else if (b >= a && b >= c) {
		return b;
	}
	else {
		return c;
	}
}
int main() {
	int choice;

	std::cout << "compare (1) numbers or (2) word?";
	std::cin >> choice;

	if (choice == 1) {
		int a, b, c;
		std::cout << "Enter first value: ";
		std::cin >> a;
		std::cout << "Enter second value: ";
		std::cin >> b;
		std::cout << "Enter third value: ";
		std::cin >> c;
		int maxNum = findMax(a, b, c);
		std::cout << "max value:" << maxNum << std::endl;

	}
	else if (choice == 2) {
		std::string a, b, c;
		std::cout << "Enter first value: ";
		std::cin >> a;
		std::cout << "Enter second value: ";
		std::cin >> b;
		std::cout << "Enter third value: ";
		std::cin >> c;
		std::string maxString = findMax(a, b, c);
		std::cout << "max value:" << maxString<< std::endl;
	}
	else {
		std::cout << "invalid choice" << std::endl;
	}
	return 0;
}
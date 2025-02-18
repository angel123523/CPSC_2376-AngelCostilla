#include <iostream>
#include <string>
#include <iomanip> 

template <typename T>
T add(T a, T b) {
	return a + b;
}
template <typename T>
T subtract(T a, T b) {
	return a - b;
}
template <typename T>
T multiply(T a, T b) {
	return a * b;
}
template <typename T>
T divide(T a, T b) {
	if (b != 0) {
		return a / b;
	}
	else {
	std::cout << "error: Division by zero!" << std::endl;
		return 0;
	}
}
template <typename T>
T Calc(T num1, T num2, T(*operation)(T, T)) {
	return operation(num1, num2);
}

int main() {
	std::string input1, input2;
	char operation;

	std::cout << "enter first number:";
	std::cin >> input1;
	std::cout << "enter second number:";
	std::cin >> input2;
	std::cout << "enter operation (=,-,*,/):";
	std::cin >> operation;

	bool isFirstDouble = input1.find('.') != std::string::npos;
	bool isSecoundDouble = input2.find('.') != std::string::npos;

	if (isFirstDouble || isSecoundDouble) {
		double num1 = std::stod(input1);
		double num2 = std::stod(input2);

		double(*op)(double, double) = nullptr;
		if (operation == '+') {
			op = add;
		}
		else if (operation == '-') {
			op = subtract;
		}
		else if (operation == '*') {
			op =multiply;
		}
		else if (operation == '/') {
			op = divide;
		}
		double result = Calc(num1, num2, op);
	std::cout << std::fixed << std::setprecision(2) << "results:" << result << std::endl;
	}
	else {
		int num1 = std::stoi(input1);
		int num2 = std::stoi(input2);

		int (*op)(int, int) = nullptr;
		if (operation == '+') {
			op = add;
		}
		else if (operation == '-') {
			op = subtract;
		}
		else if (operation == '*') {
			op = multiply;
		}
		else if (operation == '/') {
			op = divide;
		}
		int result = Calc(num1, num2, op);

		std::cout << "Result: " << result << std::endl;
	}
	return 0;
}
#include <iostream>
#include <iomanip>
#include <limits>

double convertTemp(double temp, char scale = 'F') {
	if (scale == 'F') {
		return (temp * 9.0 / 5.0) + 32;

	}
	else if (scale == 'C') {
		return (temp - 32) * 5.0 / 9.0;
	}
	return temp;
}

double getValidTempInput() {
	double temp;
	while (true) {
		std::cout << "enter Temperature:";
		std::cin >> temp;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "invalid input.";
		}
		else {
			return temp;
		}
	}
}
void Menu() {
	int choice = 0;
	double temp;
	char scale;

	std::cout << "temperature converter Menu:\n";
	std::cout << "1. convert Celsius to Fahrenheit\n";
	std::cout << "2. convert Fahrenheit to Celsius\n";
	std::cout << "Select an option:\n";

	while (choice != 1 && choice != 2) {
		std::cin >> choice;
		if (choice != 1 && choice != 2) {
			std::cout << "Invalid option. Please choose either 1 or 2: ";
		}
	}
	temp = getValidTempInput();

	if (choice == 1) {
		scale = 'F';
	}
	else {
		scale = 'C';
	}

	double convertedTemp = convertTemp(temp, scale);
	if (scale == 'F') {

		std::cout << "converted:" << std::fixed << std::setprecision(2) << convertedTemp << "°F\n";
	}
	else {
		std::cout << "converted:" << std::fixed << std::setprecision(2) << convertedTemp << "°C\n";
	}
}

int main() {
	std::cout << "Welcome to the Temperature Converter.\n";
	Menu();
	return 0;
}
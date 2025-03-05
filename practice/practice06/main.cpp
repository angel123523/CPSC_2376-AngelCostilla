#include <iostream>
#include <string>
#include "Fraction.h"
#include "MixedFraction.h"

void addFraction(Fraction& currentFraction) {
	int num, den;
	std::cout << "enter numerator and denominator of the second fraction:";
	std::cin >> num >> den;
	if (den == 0) {
		std::cout << "error: denominator cannot be zero.\n";
	}
	else {
		Fraction secondFraction(num, den);
		currentFraction = currentFraction + secondFraction;
	}
}
void subtractFraction(Fraction& currentFraction) {
	int num, den;
	std::cout << "enter numerator and denominator of the second fraction:";
	std::cin >> num >> den;
	if (den == 0) {
		std::cout << "error: denominator cannot be zero.\n";
	}
	else {
		Fraction secondFraction(num, den);
		currentFraction = currentFraction - secondFraction;
	}
}

void multiplyFraction(Fraction& currentFraction) {
	int num, den;
	std::cout << "enter numerator and denominator of the second fraction:";
	std::cin >> num >> den;
	if (den == 0) {
		std::cout << "error: denominator cannot be zero.\n";
	}
	else {
		Fraction secondFraction(num, den);
		currentFraction = currentFraction * secondFraction;
	}
}


void divideFraction(Fraction& currentFraction) {
	int num, den;
	std::cout << "enter numerator and denominator of the second fraction:";
	std::cin >> num >> den;
	if (den == 0) {
		std::cout << "error: denominator cannot be zero.\n";
	}
	else {
		Fraction secondFraction(num, den);
		if (secondFraction.GetNumerator() == 0) {
			std::cout << "error:Cannot divide by zero.\n";
		}
		else {
			currentFraction = currentFraction / secondFraction;
		}
	}
}

void displayMixedFraction(const Fraction& currentFraction) {
	MixedFraction mixedFraction(currentFraction);
	std::cout << "Mixed Fraction:" << mixedFraction << std::endl;
}

void displayMenu() {
	std::cout << "options:\n";
	std::cout << "1.Enter a Fraction manually\n";
	std::cout << "2. add a fraction\n";
	std::cout << "3. subtract a fraction\n";
	std::cout << "4. Multiply by a fraction\n";
	std::cout << "5. divide by a fraction\n";
	std::cout << " 6.display as mixed fraction\n";
	std::cout << "7.clear fraction\n";
	std::cout << "8. exit\n";
}
int main() {
	Fraction currentFraction;
	int option;

	while (true) {
		std::cout << "Current Fraction: " << currentFraction << "\n";
		displayMenu();
		std::cin >> option;

		if (option == 1) {
			int num, den;
			std::cout << "Enter numerator and denominator: ";
			std::cin >> num >> den;

			if (den == 0) {
				std::cout << "Error: Denominator cannot be zero.\n";
			}
			else {
				currentFraction.setNumerator(num);
				currentFraction.setDenominator(den);
			}
		}
		else if (option == 2) {
			addFraction(currentFraction);
		}
		else if (option == 3) {
			subtractFraction(currentFraction);
		}
		else if (option == 4) {
			multiplyFraction(currentFraction);
		}
		else if (option == 5) {
			divideFraction(currentFraction);
		}
		else if (option == 6) {
			displayMixedFraction(currentFraction);
		}
		else if (option == 7) {
			currentFraction = Fraction(); // Reset to 0/1
		}
		else if (option == 8) {
			break;
		}
	}

	return 0;
}
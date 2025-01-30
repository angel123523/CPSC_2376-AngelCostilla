#include <iostream>
#include <vector>

void printVector(const std::vector<int>& v1) {
	std::cout << "vector contains these numbers:";
	for (int num : v1) {
		std::cout << num; 
	}
	std::cout << std::endl;
}
void doubleVector(std::vector<int>& v1) {
	for (int& num : v1) {
		num *= 2;
	}
	std::cout << "when doubled the vector is: " << std::endl;
}
int calculateVector(const std::vector<int>& v1) {
	int sum = 0;
	for (int num : v1) {
		sum += num;
	}
	return sum;  
}
void printMult(const std::vector<int>& v1, int value) {
	std::cout << "mutiples of " << value << ":";
	bool found = false;
	for (int num : v1) {
		if (num % value == 0) {
			std::cout << num; 
			found = true;
		}
	}
	if (!found) {
		std::cout << "No multiples found";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> numbers;
	int choice;

	while (true) {
		std::cout << "Menu";
		std::cout << "1. add number to vector\n";
		std::cout << "2. print the vector\n";
		std::cout << "3. double the vector\n";
		std::cout << "4. find the sum of the vector\n";
		std::cout << "5 print multiple of vector\n";
		std::cout << "6. exit";
		std::cout << "Select an option.\n";
		std::cin >> choice;

		if (choice == 1) {
			int num;
			std::cout << "enter a number to add to the vector:";
			std::cin >> num;
			numbers.push_back(num);
		}
		else if (choice == 2) {
			printVector(numbers);
		}
		else if (choice == 3) {
			doubleVector(numbers);
		}
		else if (choice == 4) {
			int sum = calculateVector(numbers);
			std::cout << "Sum of the vector is: " << sum << std::endl;
		}
		else if (choice == 5) {
			int value;
			std::cout << "enter a number to find multiples of :";
			std::cin >> value;
			printMult(numbers, value);
		}
		else if (choice == 6) {
			std::cout << "exiting program." << std::endl;
			break;
		}
		else {
			std::cout << "Invalid choice, please try again." << std::endl;
		}
	}

	return 0;
}
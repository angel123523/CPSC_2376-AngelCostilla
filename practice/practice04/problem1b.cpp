#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello") {
	std::cout << prefix << "," << name << "!" << std::endl;
}

void Menu() {
	int choice = 0;
	std::string name;
	std::string prefix;

std::cout << "Greeting Menu:\n";
std::cout << "1. default Greeting\n";
std::cout << "2. greet by name\n";
std::cout << "3. custom greeting\n";
std::cout << "select an option:";
std::cin >> choice;

	if (choice == 1) {
		greet();
	}
	else if (choice == 2) {
		std::cout << "enter name:";
		std::cin >> name;
		greet(name);
	}
	else if (choice == 3) {
		std::cout << "enter greeting prefix";
		std::cin >> prefix;
		std::cout << "enter name:";
		std::cin >> name;
		greet(name, prefix);
	}
	else {
		std::cout << "invalid option. choose from 1-3\n";

	}
}
int main() {
	std::cout << "welcome to the greeting system.\n";
	Menu();
	return 0;
}
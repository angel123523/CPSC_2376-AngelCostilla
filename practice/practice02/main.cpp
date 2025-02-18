#include <iostream>
#include <fstream>
#include <string>
#include <limits>

const std::string FILENAME = "account_balance.txt";

double readBalanceFile() {
	std::ifstream inputFile(FILENAME);
	double balance;
	if (inputFile) {
		inputFile >> balance;
		inputFile.close();
	}
	else {
		balance = 100.00;
		std::ofstream outputFile(FILENAME);
		if (outputFile) {
			outputFile << balance;
			outputFile.close();
		}
		else {
			std::cerr << "error: Could not create file to store balance.\n";
			exit(1);
		}
	}
	return balance;
}

void writeBalanceFile(double balance) {
	std::ofstream outputFile(FILENAME);
	if (outputFile) {
		outputFile << balance;
		outputFile.close();
	}
	else {
		std::cerr << "error: could not write balance to file,\n";
		exit(1);
	}
}

void checkBalance(double balance) {
	std::cout << "your curret balance is: $" << balance << "\n";
	return;
}
void deposit(double& balance) {
	double amount;
	std::cout << "Enter deposit amount: $";
	while (!(std::cin >> amount) || amount <= 0) {
		std::cout << "Error: Please enter a valid positive number.\n";
		std::cout << "Enter deposit amount: $";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	balance += amount;
	writeBalanceFile(balance);
	std::cout << "deposit was Successful. Your new balance is: $" << balance;
}
void withdraw(double& balance) {
	double amount;
	std::cout << "enter withdrawal amount $";
	while (!(std::cin >> amount) || amount <= 0 || amount > balance) {
	if (amount <= 0) {
		std::cout << "error: cannot withdrawal a negitive amount.\n ";
		return;
	}
	if (amount > balance) {
		std::cout << "error: insufficient funds. your balance is $:" << balance;
		return;
	}
	std::cout << "Enter withdrawal amount: $";
	std::cin.clear();  
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
	}
	balance -= amount;
	writeBalanceFile(balance);
	std::cout << "withdrawal successful. your new balance is: $" << balance;
}
void Menu(double& balance) {
	int choice;
	do {
		std::cout << "\nMenu:\n";
		std::cout << "1. check balance\n";
		std::cout << "2. Deposit Money\n";
		std::cout << "3.Withdraw Money\n";
		std::cout << "4. exit\n";
		std::cout << "Select an option:\n";
		std::cin >> choice;
		
		while (!(std::cin >> choice) || choice < 1 || choice > 4) {
			std::cout << "Invalid choice. Please try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (choice == 1) {
			checkBalance(balance);
		}
		else if (choice == 2) {
			deposit(balance);
		}
		else if (choice == 3) {
			withdraw(balance);
		}
		else if (choice == 4) {
			std::cout << "Thank you for using the bank system. Goodbye!\n";
		}
		else {
			std::cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 4);
}

int main() {
	std::cout << "Welcom to your bank account!\n";
	double balance = readBalanceFile();
	Menu(balance);
	return 0;
}
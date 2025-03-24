#include <iostream>
#include <string>

int main() {
	float redPotion{ 0.0f };
	float bluePotion{ 0.0f };
	float* flask{ nullptr };

	std::string userChoice;
	float ammountToAdd;

	while (true) {
		std::cout << "which potion would you like to add liquid too? ( Red potion or Blue potion) type 'done' to finish:";
		std::getline(std::cin, userChoice);

		if (userChoice == "done") {
			break;
		}
		if (userChoice == "Red potion" || "red potion") {
			flask = &redPotion;
		}
		else if (userChoice == "Blue potion" || "blue potion") {
			flask = &bluePotion;
		}
		else {
			std::cout << "invalid option, choose between the 'Red potion' or 'Blue potion'.";
			continue;
		}
		std::cout << "how many milliliters do you want to add?";
		std::cin >> ammountToAdd;
		std::cin.ignore();

		if (flask != nullptr) {
			*flask += ammountToAdd;
		}
		std::cout << "Current potion levels:" << std::endl;
		std::cout << "Red potion:" << redPotion << "mL" << std::endl;
		std::cout << "blue potion:" << bluePotion << "mL" << std::endl;
	}
}
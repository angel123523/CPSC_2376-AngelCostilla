#include <iostream>
#include <deque>
#include <string>

void showMenu() {
	std::cout << "\n 1.add text" << std::endl;
	std::cout << "\n 2. Undo last edit" << std::endl;
	std::cout << "\n 3. show content" << std::endl;
	std::cout << "\n 4. exit" << std::endl;
	std::cout << "choice:";
}

void addText(std::deque<std::string>& content) {
	std::string text;
	std::cout << "enter text:";
	std::cin.ignore();
	std::getline(std::cin, text);
	content.push_back(text);
	std::cout << "text added" << std::endl;
}
void undoLastEdit(std::deque<std::string>& content) {
	if (content.empty()) {
		std::cout << "no edit to undo" << std::endl;
	}
	else {
		content.pop_back();
		std::cout << "undo succesfully" << std::endl;
	}
}
void showContent(const std::deque<std::string>& content) {
	if(content.empty()) {
		std::cout << "no content available" << std::endl;
	}
	else {
		std::cout << "current content:";
		for (const auto& text : content) {
			std::cout << text << "";
		}
		std::cout << std::endl;
	}
}
int main() {
	std::deque<std::string> content;
	int choice;

	while (true) {
		showMenu();
		std::cin >> choice;

		if (choice == 1) {
			addText(content);
		}
		else if (choice == 2) {
			undoLastEdit(content);
		}
		else if (choice == 3) {
			showContent(content);
		}
		else if (choice == 4) {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else {
			std::cout << "Invalid choice, try again" << std::endl;
		}
	}

	return 0;
}

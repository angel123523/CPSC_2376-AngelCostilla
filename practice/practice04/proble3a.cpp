#include <string>
#include <list>
#include <iostream>

void showMenu() {
	std::cout << "\n1.add task" << std::endl;
	std::cout << "2. remove task" << std::endl;
	std::cout << "3.show task" << std::endl;
	std::cout << "4.Exit" << std::endl;
	std::cout << "choice:" << std::endl;
}

void addtask(std::list<std::string>& tasks) {
	std::string task;
	std::cout << "enter task:";
	std::cin.ignore();
	std::getline(std::cin, task);
	tasks.push_back(task);
	std::cout << "task added" << std::endl;
}
void removetask(std::list<std::string>& tasks) {
	int taskNum;
	std::cout << "enter task to remove:";
	std::cin >> taskNum;
	if(taskNum<1 || taskNum>tasks.size()) {
		std::cout << "invalid task number" << std::endl;
		return;
	}
	auto it = tasks.begin();
	std::advance(it, taskNum - 1);
	tasks.erase(it);
	std::cout << "task removed" << std::endl;

}

void showtask(const std::list<std::string>& tasks) {
	if (tasks.empty()) {
		std::cout << "no task assigned" << std::endl;
		return;
	}
	std::cout << "task:" << std::endl;
	int cout = 1;
	for (const auto& task : tasks) {
		std::cout << cout++ << "." << task << std::endl;
	}
}
int main() {
	std::list<std::string> tasks;
	int choice;

	while (true) { 
		showMenu();
		std::cin >> choice;

		if (choice == 1) {
			addtask(tasks);
		}
		else if (choice == 2) {
			removetask(tasks);
		}
		else if (choice == 3) {
			showtask(tasks);
		}
		else if (choice == 4) {
			std::cout << "Exiting" << std::endl;
			break;
		}
		else {
			std::cout << "Invalid choice, try again" << std::endl;
		}
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>

class BoardGame {
public:
    std::string name;
    int totalCopies;
    int availableCopies;

   
    BoardGame(std::string name, int totalCopies) {
        this->name = name;
        this->totalCopies = totalCopies;
        this->availableCopies = totalCopies;
    }
    void updateAvailableGames(bool returned) {
        if (returned) {
            availableCopies++;
        }
        else {
            availableCopies--;
        }
    }
};
class Customer {
public:
    std::string name;
    int customerID;

    Customer(std::string name, int customerID) {
        this->name = name;
        this->customerID = customerID;
    }

    void checkoutGame(BoardGame& game, std::string dueDate) {
        if (game.availableCopies > 0) {
            game.updateAvailableGames(false);
            std::cout << name << " checked out " << game.name << " (Due: " << dueDate << ")\n";
        }
        else {
            std::cout << "Sorry, " << game.name << " is out of stock.\n";
        }
    }
    void returnGame(BoardGame& game) {
        game.updateAvailableGames(true);
        std::cout << name << " returned " << game.name << ".\n";
    }
};

class Transaction {
public:
    Customer borrower;
    BoardGame borrowedGame;
    std::string checkoutDate;
    std::string dueDate;
    Transaction(Customer borrower, BoardGame borrowedGame, std::string checkoutDate, std::string dueDate)
        : borrower(borrower), borrowedGame(borrowedGame), checkoutDate(checkoutDate), dueDate(dueDate) {
    }
    void completeTransaction() {
        borrowedGame.updateAvailableGames(true);
        std::cout << borrower.name << " completed the transaction for returning " << borrowedGame.name << ".\n";
    }
};

void listGames(const std::vector<BoardGame>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& game : inventory) {
        std::cout << game.name << " - " << game.availableCopies << " available\n";
    }
}
int main() {
    std::vector<BoardGame> inventory = {
       BoardGame("Catan", 5),
       BoardGame("Monopoly", 3),
       BoardGame("Pandemic", 4)
    };

    Customer customer1("Alice", 1);
    Customer customer2("Bob", 2);

    listGames(inventory);

    customer1.checkoutGame(inventory[0], "2025-04-20");

    customer2.checkoutGame(inventory[0], "2025-04-22");

    customer1.returnGame(inventory[0]);

    listGames(inventory);

    return 0;
}
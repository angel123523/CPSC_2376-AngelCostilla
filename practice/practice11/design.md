```mermaid
classDiagram
    class BoardGame {
        +std::string name
        +int totalCopies
        +int availableCopies
        +BoardGame(std::string name, int totalCopies)
        +void updateAvailability(bool returned)
    }

    class Customer {
        +std::string name
        +int customerID
        +Customer(std::string name, int customerID)
        +void checkoutGame(BoardGame& game, std::string dueDate)
        +void returnGame(BoardGame& game)
    }

    class Transaction {
        +Customer borrower
        +BoardGame borrowedGame
        +std::string checkoutDate
        +std::string dueDate
        +Transaction(Customer borrower, BoardGame borrowedGame, std::string checkoutDate, std::string dueDate)
        +void completeTransaction()
    }

    BoardGame "1" -- "*" Transaction : has
    Customer "1" -- "*" Transaction : initiates
   ```
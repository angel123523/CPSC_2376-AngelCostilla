#include <iostream>
#include "minesweeper.h"

std::ostream& operator<<(std::ostream& os, const GameStatus& status) { // had trouble getting this file to work, and chatgpt suggested the switch statements. 
    switch (status) {
    case GameStatus::ONGOING:
        os << "Ongoing";
        break;
    case GameStatus::PLAYER_1_WINS:
        os << "Player 1 Wins";
        break;
    case GameStatus::PLAYER_2_WINS:
        os << "Player 2 Wins";
        break;
    case GameStatus::DRAW:
        os << "Draw";
        break;
    }
    return os;
}

int main() {
    bool playAgain = true; 

    while (playAgain){
    Minesweeper game(5, 5, 5);

    while (game.status()==GameStatus::ONGOING){
        game.display();
        int row, col;
        std::cout << "player" << (game.status() == GameStatus::ONGOING ? game.getCurrentPlayer() : 1) 
            << ", enter row and colum(example: 3 3)";
        std::cin >> row >> col;
        game.play(row, col);

        if (game.status() != GameStatus::ONGOING) {
            if (game.status() == GameStatus::PLAYER_1_WINS) {
                std::cout << "Player 1 Wins!" << std::endl;
            }
            else if (game.status() == GameStatus::PLAYER_2_WINS) {
                std::cout << "Player 2 Wins!" << std::endl;
            }
            std::cout << "Final Status: " << game.status() << std::endl;
            playAgain = game.askToPlayAgain();
            break;
          }
        }
    }

    std::cout << "Thanks for playing." << std::endl;
    return 0;
}
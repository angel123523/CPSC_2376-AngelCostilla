#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

enum class GameState {
	ONGOING,
	PLAYER_1_WINS,
	PLAYER_2_WINS,
	DRAW
};

enum class CellState {
	COVERED,
	REVEALED,
	MINE
};

class Minesweeper {
private:
	std::vector<std::vector<int>> board;
	std::vector<std::vector<CellState>> display;
	int rows, cols, totalMines;
	int player1Score, player2Score;
	int currentPlayer;

	void makeboard() {
		board = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
		display = std::vector<std::vector<CellState>>(rows, std::vector<CellState>(cols, CellState::COVERED));

		std::srand(std::time(0));
		int minesPlaced = 0;
		while (minesPlaced < totalMines) {
			int r = std::rand() % rows;
			int c = std::rand() % cols;
			if (board.at(r).at(c) == -1) {
				continue;
			}
			board.at(r).at(c) = -1;
			++minesPlaced;

			for (int dr = -1;dr <= 1;++dr) {
				for (int dc = -1;dc <= 1;++dc) {
					if (r + dr >= 0 && r + dr < rows && c + dc >= 0 && c + dc < cols && board.at(r + dr).at(c + dc) != -1) {
						++board.at(r + dr).at(c + dc);
					}
				}
			}
		}
	}

	void printboard() {
		std::cout << "\nboard state (use row and column to input):\n";
		std::cout << "  ";
		for (int c = 0; c < cols;++c) {
			std::cout << " " << c << " ";
		}
		std::cout << std::endl;
		for (int r = 0; r < rows;++r) {
			std::cout << r << " ";
			for (int c = 0;c < cols;++c) {
				if (display.at(r).at(c) == CellState::COVERED) {
					std::cout << "[#]";
				}
				else if (display.at(r).at(c) == CellState::REVEALED) {
					if (board.at(r).at(c) == -1) {
						std::cout << "[M]";
					}
					else {
						std::cout << "[" << board.at(r).at(c) << "[";
					}
				}
				else {
					std::cout << "[x]";
				}
			}
			std::cout << std::endl;
		}
	}

	bool revealCell(int r, int c) {
		if (r < 0 || r >= rows || c < 0 || c >= cols || display.at(r).at(c) == CellState::REVEALED) {
			return false;
		}
		display.at(r).at(c) = CellState::REVEALED;
		if (board.at(r).at(c) == -1) {
			return true;
		}
		return false;
	}
	GameState gameStatus() {
		bool player1Safe = true, player2Safe = true;

		for (int r = 0; r < rows; ++r) {
			for (int c = 0; c < cols; ++c) {
				if (display.at(r).at(c) == CellState::REVEALED) {
					if (board.at(r).at(c) == -1) {
					
						if (currentPlayer == 1) {
							player1Safe = false;
						}
						else {
							player2Safe = false;
						}
					}
				}
			}
		}
		if (!player1Safe)return GameState::PLAYER_2_WINS;
		if (!player2Safe)return GameState::PLAYER_1_WINS;

		return GameState::ONGOING;
	};
	void switchTurn() {
		currentPlayer = (currentPlayer = 1) ? 2 : 1;
	}

	bool playTurn() {
		int row,col;
		std::cout << "player" << currentPlayer << "'s turn, enter row and column( ex: 2 4 for row 2, column 4):";
		while (true) {
			std::cin >> row >> col;
			if (std::cin.fail() || row < 0 || row >= rows || col < 0 || col >= cols || display.at(row).at(col) == CellState::REVEALED) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter row and column (e.g., '2 3'): ";
			}
			else {
				break;
			}
		}
		bool hitMine = revealCell(row, col);
		if (hitMine) {
			std::cout << "player" << currentPlayer << " you hit a mine!" << std::endl;
			return true;
		}

		if (currentPlayer == 1) {
			player1Score++;
		}
		else {
			player2Score++;
		}
		return false;
	}
public:
	Minesweeper(int r, int c, int mines) : rows(r), cols(c), totalMines(mines), player1Score(0), player2Score(0), currentPlayer(1) {
		makeboard();
	}
	void explainRules() {
		std::cout << "Welcome to Minesweeper- Rules:\n";
		std::cout << "1.players take turn selecting squares on the grid.\n";
		std::cout << "2. players get points for every square they select that dosent explode.\n";
		std::cout << "the game ends when a player hits a mine.\n";
	}
	void play() {
		while (true) {
			printboard();
			bool hitMine = playTurn();
			if (hitMine) {
				if (currentPlayer == 1) {
					std::cout << "Player 2 Wins! Final Score: Player 1 = " << player1Score << ", Player 2 = " << player2Score << std::endl;
				}
				else {
					std::cout << "Player 1 Wins! Final Score: Player 1 = " << player1Score << ", Player 2 = " << player2Score << std::endl;
				}
				break;
			}
			switchTurn();
		}
	}
	bool askToPlayAgain() {
		char choice;
		std::cout << "do yo want to play again? (y/n):";
		std::cin >> choice;
		return(choice == 'y' || choice == 'Y');
	}
};
int main() {
	Minesweeper game(5, 5, 5);
	game.explainRules();

	do {
		game.play();
	} while (game.askToPlayAgain());
	std::cout << "thanks for playing!" << std::endl;
	return 0;
}
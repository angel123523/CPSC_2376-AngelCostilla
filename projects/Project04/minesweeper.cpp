#include "minesweeper.h"


void Minesweeper::makeBoard() {
	board = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
	boardDisplay = std::vector<std::vector<CellState>>(rows, std::vector<CellState>(cols, CellState::COVERED));

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
void Minesweeper::draw(Engine& engine, int hoverRow, int hoverCol) const {
	int cellSize = 100;
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			SDL_Color color = { 50, 50, 50, 255 };

			if (boardDisplay[r][c] == CellState::REVEALED) {
				color = { 200, 200, 200, 255 };
			}
			else if (r == hoverRow && c == hoverCol) {
				color = { 100, 100, 150, 255 }; // hover highlight
			}

			engine.drawRectangle(c * cellSize + cellSize / 2, r * cellSize + cellSize / 2, cellSize, cellSize, color);

			if (boardDisplay[r][c] == CellState::REVEALED) {
				std::string text = (board[r][c] == -1) ? "M" : std::to_string(board[r][c]);

			}
		}
	}
}
void Minesweeper::printBoard() const {
	std::cout << "\nboard state (use row and column to input):\n";
	std::cout << "  ";
	for (int c = 0; c < cols;++c) {
		std::cout << " " << c << " ";
	}
	std::cout << std::endl;
	for (int r = 0; r < rows;++r) {
		std::cout << r << " ";
		for (int c = 0;c < cols;++c) {
			if (boardDisplay.at(r).at(c) == CellState::COVERED) {
				std::cout << "[#]";
			}
			else if (boardDisplay.at(r).at(c) == CellState::REVEALED) {
				if (board.at(r).at(c) == -1) {
					std::cout << "[M]";
				}
				else {
					std::cout << "[" << board.at(r).at(c) << "]";
				}
			}
			else {
				std::cout << "[x]";
			}
		}
		std::cout << std::endl;
	}
}
bool Minesweeper::revealCell(int r, int c) {
	if (r < 0 || r >= rows || c < 0 || c >= cols || boardDisplay.at(r).at(c) == CellState::REVEALED) {
		return false;
	}
	boardDisplay.at(r).at(c) = CellState::REVEALED;
	if (board.at(r).at(c) == -1) {
		return true;
	}
	return false;
}
void Minesweeper::switchTurn() {
	currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
bool Minesweeper::isValidMove(int row, int col) const {
	return row >= 0 && row < rows && col >= 0 && col < cols && boardDisplay.at(row).at(col) == CellState::COVERED;
}
Minesweeper::Minesweeper(int r, int c, int mines) : rows(r), cols(c), totalMines(mines), player1Score(0), player2Score(0), currentPlayer(1) {
	makeBoard();
}
GameStatus Minesweeper::status() const {
	bool player1Safe = true, player2Safe = true;

	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			if (boardDisplay.at(r).at(c) == CellState::REVEALED) {
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
	if (!player1Safe) return GameStatus::PLAYER_2_WINS;
	if (!player2Safe) return GameStatus::PLAYER_1_WINS;

	return GameStatus::ONGOING;
}
void Minesweeper::play(int row, int col) {
	if(!isValidMove(row,col)) return;

	bool hitMine= revealCell(row, col);
	if (hitMine) {
		std::cout << "player" << currentPlayer << "hit a mine." << std::endl;
		return; 
	}
	if (currentPlayer == 1) {
		player1Score++;
	}
	else {
		player2Score++;
	}
	switchTurn(); 
}
void Minesweeper::display() const {
	printBoard();
}
bool Minesweeper::askToPlayAgain() const {
	char choice;
	std::cout << "do you want to play again? (y/n)";
	std::cin >> choice;
	return (choice == 'y' || choice == 'Y');

}


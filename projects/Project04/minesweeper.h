#pragma once
#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <vector>
#include <iostream>
#include "Engine.h"


enum GameStatus {
	ONGOING,
	PLAYER_1_WINS,
	PLAYER_2_WINS,
	DRAW
};

enum  CellState {
	COVERED,
	REVEALED,
	MINE

};
class Minesweeper {
private:
	std::vector<std::vector<int>> board;
	std::vector<std::vector<CellState>> boardDisplay;
	int rows, cols, totalMines;
	int player1Score, player2Score;
	int currentPlayer;

	void makeBoard();
	bool revealCell(int r, int c);
	void switchTurn();
	void printBoard() const;
	bool isValidMove(int row, int col) const;

public:
	Minesweeper(int r, int c, int mines);
	GameStatus status() const;
	void play(int row, int col);
	void display() const;
	bool askToPlayAgain() const;
	int getCurrentPlayer() const {
		return currentPlayer;
	}
	void draw(Engine& engine, int hoverRow = -1, int hoverCol = -1) const;
};
#endif // MINESWEEPER_H

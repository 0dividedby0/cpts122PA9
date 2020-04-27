#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Board.h"

using std::endl;
using std::cout;

class Checker {
public:
	Checker(int newNeedToWin = 3, int newSize = 3);
	bool hasWon(int newX, int newY, Piece *newPieceToCheck, Board *boardToCheck);
	void setNeedToWin(int newNeedToWin);
	void setSize(int newSize);
private:
	int needToWin, Size;
	Piece *pieceToCheck;
	Board *board;

	int countRight(int x, int y, int counter);
	int countLeft(int x, int y, int counter);
	int countDown(int x, int y, int counter);
	int countUp(int x, int y, int counter);
	int countUpLeftDiagonal(int x, int y, int counter);
	int countDownLeftDiagonal(int x, int y, int counter);
	int countDownRightDiagonal(int x, int y, int counter);
	int countUpRightDiagonal(int x, int y, int counter);
};


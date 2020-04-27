#include "Checker.h"

Checker::Checker(int newNeedToWin, int newSize) {
	needToWin = newNeedToWin;
	Size = newSize;
	pieceToCheck = nullptr;
	board = nullptr;
}
void Checker::setNeedToWin(int newNeedToWin) {
	needToWin = newNeedToWin;
}
void Checker::setSize(int newSize) {
	Size = newSize;
}

bool Checker::hasWon(int newX, int newY, Piece *newPieceToCheck, Board *boardToCheck) {

	board = boardToCheck;
	pieceToCheck = newPieceToCheck;

	int right = 0, left = 0, up = 0, down = 0, lDDiagonal = 0, rDDiagoanl = 0, lUDiagonal = 0, rUDiagonal = 0; // counting all peices around
	int count = 0;

	if (board != nullptr) {
		right = countRight(newX, newY, count);
		count = 0;
		left = countLeft(newX, newY, count);
		count = 0;
		up = countUp(newX, newY, count);
		count = 0;
		down = countDown(newX, newY, count);
		count = 0;
		lDDiagonal = countDownLeftDiagonal(newX, newY, count);
		count = 0;
		rDDiagoanl = countDownRightDiagonal(newX, newY, count);
		count = 0;
		lUDiagonal = countUpLeftDiagonal(newX, newY, count);
		count = 0;
		rUDiagonal = countUpRightDiagonal(newX, newY, count);

		if (right + left >= needToWin + 1) // checking for needToWin + 1 because it counts the start 2 times.
										   // So, if it was  x x x and we started in the middle it would count 
										   // the middle piece when it goes right and when it goes left. 
		{
			cout << "Piece wins, Horizontally" << endl;
			return true;
		}
		else if (up + down >= needToWin + 1)
		{
			cout << "Piece wins, Vertically" << endl;
			return true;
		}
		else if (rUDiagonal + lDDiagonal >= needToWin + 1)
		{
			cout << "Piece wins, Diagonally" << endl;
			return true;
		}
		else if (rDDiagoanl + lUDiagonal >= needToWin + 1)
		{
			cout << "Piece wins, Diagonally" << endl;
			return true;
		}
		else // not enough in a row
		{
			return false;
		}
	}
	return false;
}


int Checker::countRight(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size) //checks bounds
	{
		if (board->getBoardState(x,y) == nullptr) // when it encounters a piece that isnt an 'x' it will return adding 1 for each level of recursion.
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countRight(x + 1, y, counter) + 1;
	}

	return counter;// in the end it returns all of the 'x' characters to the right including itself.
}
int Checker::countLeft(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size)
	{
		if (board->getBoardState(x,y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countLeft(x - 1, y, counter) + 1;
	}

	return counter;

}
int Checker::countDown(int x, int y, int counter) {
	if (x >= 0 && x < Size && y >= 0 && y<Size)
	{
		if (board->getBoardState(x, y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countDown(x, y + 1, counter) + 1;
	}

	return counter;
}
int Checker::countUp(int x, int y, int counter) {
	if (x >= 0 && x < Size && y >= 0 && y<Size)
	{
		if (board->getBoardState(x, y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countUp(x, y - 1, counter) + 1;
	}

	return counter;

}
int Checker::countUpLeftDiagonal(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size)
	{
		if (board->getBoardState(x,y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countUpLeftDiagonal(x - 1, y + 1, counter) + 1;
	}

	return counter;
}
int Checker::countDownLeftDiagonal(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size )
	{
		if (board->getBoardState(x,y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countDownLeftDiagonal(x - 1, y - 1, counter) + 1;
	}

	return counter;
}
int Checker::countDownRightDiagonal(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size)
	{
		if (board->getBoardState(x,y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countDownRightDiagonal(x + 1, y - 1, counter) + 1;
	}

	return counter;
}
int Checker::countUpRightDiagonal(int x, int y, int counter) {
	if (x >= 0 && x < Size && y>=0 && y<Size)
	{
		if (board->getBoardState(x,y) == nullptr)
		{
			return 0;
		}
		else if (board->getBoardState(x, y)->getIdentifier() != pieceToCheck->getIdentifier()) {
			return 0;
		}
		counter = countUpRightDiagonal(x + 1, y + 1, counter) + 1;
	}

	return counter;
}
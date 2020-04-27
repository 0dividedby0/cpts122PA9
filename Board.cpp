#include "Board.h"

Board::Board() {
	size = 3;
	players = 2;
	turn = 0;

	generateLines();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			boardState[i][j] = nullptr;
		}
	}
}

void Board::setSize(int newSize) {
	size = newSize;

	generateLines();
}
void Board::setPlayers(int newPlayers) {
	players = newPlayers;
}
void Board::setBoardState(int x, int y) {
	
	switch (turn) {
	case 0:
		boardState[x][y] = new Piece1();
		break;
	case 1:
		boardState[x][y] = new Piece2();
		break;
	case 2:
		boardState[x][y] = new Piece3();
		break;
	case 3:
		boardState[x][y] = new Piece4();
		break;
	default:
		boardState[x][y] = new Piece1();
	}

	float tempX = (-50 - x*(700 / (float)size)) / (3.0 / (size));
	float tempY = (-50 - y*(700 / (float)size)) / (3.0 / (size));
	
	boardState[x][y]->getSprite().setOrigin(sf::Vector2f(tempX, tempY));

	boardState[x][y]->getSprite().scale(sf::Vector2f(3.0/size, 3.0/size));

	switch (turn) {
	case 0:
		turn = 1;
		break;
	case 1:
		if (players == 2) {
			turn = 0;
		}
		else {
			turn = 2;
		}
		break;
	case 2:
		if (players == 3) {
			turn = 0;
		}
		else {
			turn = 3;
		}
		break;
	case 3:
		turn = 0;
		break;
	default:
		turn = 0;
		break;
	}
}

int Board::getSize() {
	return size;
}
int Board::getPlayers() {
	return players;
}
int Board::getTurn() {
	return turn;
}
Piece *Board::getBoardState(int x, int y) {
	return boardState[x][y];
}
sf::RectangleShape* Board::getHBoard(int x) {
	return hBoard[x];
}
sf::RectangleShape* Board::getVBoard(int x) {
	return vBoard[x];
}

void Board::generateLines() {
	for (int i = 1; i < size; i++) {
		hBoard[i - 1] = new sf::RectangleShape(sf::Vector2f(700, 10));
		hBoard[i - 1]->setPosition(sf::Vector2f((float)50, (float)(50 + (i*(700 / size)))));
		hBoard[i - 1]->setFillColor(sf::Color::Red);
		vBoard[i - 1] = new sf::RectangleShape(sf::Vector2f(10, 700));
		vBoard[i - 1]->setPosition(sf::Vector2f((float)(50 + (i*(700 / size))), (float)50));
		vBoard[i - 1]->setFillColor(sf::Color::Red);
	}
}

void Board::resetBoard() {
	size = 3;
	players = 2;
	turn = 0;

	generateLines();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			boardState[i][j] = nullptr;
		}
	}
}
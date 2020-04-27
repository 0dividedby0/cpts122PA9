#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Pieces.h"

class Board {
public:
	Board();

	void setSize(int newSize);
	void setPlayers(int newPlayers);
	void setBoardState(int x, int y);

	void resetBoard();

	int getSize();
	int getPlayers();
	int getTurn();
	Piece *getBoardState(int x, int y);
	sf::RectangleShape* getHBoard(int x);
	sf::RectangleShape* getVBoard(int x);

	void generateLines();
private:
	int size, turn, players;
	Piece *boardState[10][10];

	sf::RectangleShape *hBoard[9];
	sf::RectangleShape *vBoard[9];
};
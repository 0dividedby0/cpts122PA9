#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using std::string;
using std::cout;

class Piece {
public:
	Piece(string fileName = "xPiece.png", int newidentifier = 0);
	sf::Sprite &getSprite();
	void setTexture(string fileName);
	int getIdentifier();

protected:
	int identifier;
	sf::Texture texture;
	sf::Sprite sprite;
};
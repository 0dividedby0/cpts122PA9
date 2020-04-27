#include "Piece.h"

Piece::Piece(string fileName, int newidentifier) {
	texture.loadFromFile(fileName);
	sprite.setTexture(texture);
	identifier = newidentifier;
}

int Piece::getIdentifier() {
	return identifier;
}

sf::Sprite &Piece::getSprite() {
	return sprite;
}

void Piece::setTexture(string fileName) {
	sf::Texture tempTexture;
	tempTexture.loadFromFile(fileName);
	sprite.setTexture(tempTexture);
}
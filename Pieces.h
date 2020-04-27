#pragma once
#include "Piece.h"

class Piece1 : public Piece {
public:
	Piece1(string fileName = "xPiece.png", int identifier = 1) : Piece(fileName, identifier) {}
};

class Piece2 : public Piece {
public:
	Piece2(string fileName = "oPiece.png", int identifier = 2) : Piece(fileName, identifier) {}
};

class Piece3 : public Piece {
public:
	Piece3(string fileName = "yPiece.png", int identifier = 3) : Piece(fileName, identifier) {}
};

class Piece4 : public Piece {
public:
	Piece4(string fileName = "xPiece.png", int identifier = 4) : Piece(fileName, identifier) {}
};

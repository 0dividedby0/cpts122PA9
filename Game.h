#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Board.h"
#include "Checker.h"
#include "Networking.h"

using std::endl;
using std::cout;

class Game {
public:
	int startGame();

	string getDimensionString();
private:
	Board gameBoard;
	Checker boardCheck;
	Networking networker;
};

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "Board.h"
#include "Checker.h"

#pragma comment(lib, "sfml-network.lib")

using std::endl;
using std::cout;
using std::cin;

class Networking {
public:
	void printIP();
	int startHosting();
	void setupGameHost(int newNumPlayers, int newBoardSize);
	void sendNewMove(int x, int y);
	void sendTurn(int turn);
	void recievePosition(int *newX, int *newY);

	int startConnecting();
	void setupClientGame(int *newNumPlayers, int *newBoardSize);
	void recieveNewMove(int *newX, int *newY);
	int recieveTurn();
	void sendPositionToHost(int x, int y);
	
	bool isYourTurn(int curTurn);
	int getPlayerID();
private:
	int numPlayers = 0;
	int tempTurn = 0;
	int playerID = 0;
	sf::TcpSocket clients[3];
};

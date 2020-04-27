#include "Networking.h"

void Networking::printIP() {
	sf::IpAddress hostAddress = sf::IpAddress::getLocalAddress();
	string IP = hostAddress.toString();
	cout << "Host IP: " << IP << endl;
}
int Networking::startHosting() {
	//start hosting by opening a listener
	sf::TcpListener listener;

	//set the number of players to one
	int numPlayers = 1;

	//helper variable
	int playOrWait;

	// bind the listener to a port
	if (listener.listen(53000) != sf::Socket::Done)
	{
		// error...
	}

	for (int i = 0; i < 3; i++) {
		//look for clients
		listener.accept(clients[i]);
		//print client IP when connected
		cout << "Client IP: " << clients[i].getRemoteAddress();
		//increment players
		numPlayers++;

		//prompt host to start game and gets option
		cout << "\nThere are " << numPlayers << " players.\n" << "1. Start Game\n2. Wait for More Players\n3. Stop Hosting\nChoice: ";
		cin >> playOrWait;
		if (playOrWait != 2) {
			break;
		}
	}

	if (playOrWait == 3) {
		for (int i = 0; i < numPlayers - 1; i++) {
			//lets clients know they are disconnected
			clients[i].send("Disconnected :(", 16);
		}
		return -1;
	}
	else if (numPlayers > 1) {
		for (int i = 0; i < numPlayers - 1; i++) {
			//lets clients know they are connected
			clients[i].send("Connected!", 16);
		}
		//starts game with numPlayers or 2;
		cout << "Starting Game!" << endl;
		return numPlayers;
	}
	return -2;
}

int Networking::startConnecting() {
	//get host IP from client
	cout << "Enter Host IP: ";
	string hostIP;
	cin >> hostIP;

	//connect to the host with given IP
	sf::Socket::Status status = clients[0].connect(hostIP, 53000);

	//checks connection status
	char connectStatus[16];
	std::size_t received;

	clients[0].receive(connectStatus, 16, received);

	cout << connectStatus << endl;

	//starts game
	if (strcmp(connectStatus, "Connected!") == 0) {
		cout << "Starting Game!" << endl;
		return 1;
	}
	else {
		cout << "Returning to Menu!";
		return -1;
	}

}

void Networking::setupClientGame(int *newNumPlayers, int *newBoardSize) {
	char numPlayers[16], boardSize[16], newPlayerID[16];
	std::size_t received;

	clients[0].receive(newPlayerID, 16, received);
	playerID = atoi(newPlayerID);
	cout << "Your player ID: " << playerID << endl;

	clients[0].receive(numPlayers, 16, received);
	*newNumPlayers = atoi(numPlayers);

	clients[0].receive(boardSize, 16, received);
	*newBoardSize = atoi(boardSize);
}

void Networking::setupGameHost(int newNumPlayers, int newBoardSize) {
	for (int i = 0; i < newNumPlayers - 1; i++) {
		//lets clients know they are disconnected
		char buffer[16];
		clients[i].send(itoa(i+1, buffer, 10), 16);
		clients[i].send(itoa(newNumPlayers, buffer, 10), 16);
		clients[i].send(itoa(newBoardSize, buffer, 10), 16);
	}
	cout << "Your player ID: " << playerID << endl;
	numPlayers = newNumPlayers;
}

void Networking::sendNewMove(int x, int y) {
	for (int i = 0; i < numPlayers - 1; i++) {
		//lets clients know they are disconnected
		char buffer[16];
		clients[i].send(itoa(x, buffer, 10), 16);
		clients[i].send(itoa(y, buffer, 10), 16);
	}
}
void Networking::sendTurn(int turn) {
	for (int i = 0; i < numPlayers - 1; i++) {
		//lets clients know they are disconnected
		char buffer[16];
		clients[i].send(itoa(turn, buffer, 10), 16);
	}
	tempTurn = turn;
}

void Networking::recievePosition(int *newX, int *newY) {
	char newXC[16], newYC[16];
	std::size_t received;

	cout << "Turn is " << tempTurn;

	clients[tempTurn-1].receive(newXC, 16, received);
	*newX = atoi(newXC);

	clients[tempTurn-1].receive(newYC, 16, received);
	*newY = atoi(newYC);

	cout << "Host recieved position at " << *newX << *newY;
}

void Networking::recieveNewMove(int *newX, int *newY) {
	char newYC[16], newXC[16];
	std::size_t received;

	clients[0].receive(newXC, 16, received);
	*newX = atoi(newXC);

	clients[0].receive(newYC, 16, received);
	*newY = atoi(newYC);
}
int Networking::recieveTurn() {
	char newTurn[16];
	std::size_t received;

	clients[0].receive(newTurn, 16, received);
	 return atoi(newTurn);
}
void Networking::sendPositionToHost(int x, int y) {
	char buffer[16];

	cout << "Client sends position " << x << y;

	clients[0].send(itoa(x, buffer, 10), 16);
	clients[0].send(itoa(y, buffer, 10), 16);
}


int Networking::getPlayerID() {
	return playerID;
}

bool Networking::isYourTurn(int curTurn) {
	return curTurn == playerID ? true : false;
}


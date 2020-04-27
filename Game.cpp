#include "Game.h"

int Game::startGame() {
	//initializes and opens window
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Tic Tac Twist");
	window.setFramerateLimit(60);
	int turnCounter = 0, victor = -1;

	//*************************rectangle setup**************************
	//size slider setup
	sf::RectangleShape sizeSelector(sf::Vector2f(10, 280));
	sizeSelector.setFillColor(sf::Color::Blue);
	sizeSelector.setPosition(sf::Vector2f(825, 250));

	//setup mask rectangle
	sf::RectangleShape mask(sf::Vector2f(1000, 800));
	mask.setFillColor(sf::Color(0, 0, 0, 200));
	mask.setPosition(sf::Vector2f(0, 0));

	//pause button setup
	sf::RectangleShape pause1(sf::Vector2f(10, 30));
	pause1.setFillColor(sf::Color::Black);
	pause1.setPosition(sf::Vector2f(950, 20));

	sf::RectangleShape pause2(sf::Vector2f(10, 30));
	pause2.setFillColor(sf::Color::Black);
	pause2.setPosition(sf::Vector2f(930, 20));

	//////////////////////////////////////////////////game over setup///////////////////////////////////////////////////
	sf::RectangleShape button_background(sf::Vector2f(175, 78));//creating the rectangle for background of buttons
	sf::RectangleShape button_background2(sf::Vector2f(175, 78));

	button_background2.setFillColor(sf::Color::White);//coloring rectangles White
	button_background.setFillColor(sf::Color::White);

	button_background.setPosition(235, 650);
	button_background2.setPosition(595, 650);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////options setup///////////////////////////////////////////////////
	sf::RectangleShape host_button(sf::Vector2f(500, 100));//creating the rectangle for background of buttons
	sf::RectangleShape connect_button(sf::Vector2f(500, 100));
	sf::RectangleShape quit_button(sf::Vector2f(500, 100));
	sf::RectangleShape back_button(sf::Vector2f(500, 100));
	sf::RectangleShape two_player_button(sf::Vector2f(50, 50));
	sf::RectangleShape three_player_button(sf::Vector2f(50, 50));
	sf::RectangleShape four_player_button(sf::Vector2f(50, 50));

	host_button.setFillColor(sf::Color::White);//coloring rectangles White
	connect_button.setFillColor(sf::Color::White);
	quit_button.setFillColor(sf::Color::White);//coloring rectangles White
	back_button.setFillColor(sf::Color::White);
	two_player_button.setFillColor(sf::Color::White);
	three_player_button.setFillColor(sf::Color::White);
	four_player_button.setFillColor(sf::Color::White);

	host_button.setPosition(100, 150);
	connect_button.setPosition(100, 300);
	quit_button.setPosition(100, 450);
	back_button.setPosition(100, 600);
	two_player_button.setPosition(700, 200);
	three_player_button.setPosition(770, 200);
	four_player_button.setPosition(840, 200);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////Pause menu///////////////////////////////////////////////////////////
	sf::RectangleShape new_game_button(sf::Vector2f(570, 100));//creating the rectangle for background of buttons

	new_game_button.setFillColor(sf::Color::White);//coloring rectangles White

	new_game_button.setPosition(100, 150);
	//*********************************************************************/


	//*************************polygon setup**************************
	//size marker setup
	sf::CircleShape circleMarker(15);
	circleMarker.setFillColor(sf::Color::Green);
	circleMarker.setPosition(sf::Vector2f(815, 235));

	//play button setup
	sf::CircleShape playButton(15, 3);
	playButton.setFillColor(sf::Color::Green);
	playButton.setPosition(sf::Vector2f(900, 400));
	playButton.rotate(90);

	//player indicator setup
	sf::CircleShape playerIndicator(10);
	playerIndicator.setFillColor(sf::Color::Blue);
	//*********************************************************************/


	//*************************text setup**************************
	sf::Font font;
	font.loadFromFile("MAIAN.ttf");
	sf::Text play, dimension, player1Indicator, player2Indicator, player3Indicator, player4Indicator, options,
		hostText, connect, quit, back, number_of_players, number_boxes, new_game;
	play.setFont(font);
	play.setCharacterSize(30);
	play.setColor(sf::Color::Black);
	play.setString("Play");
	play.setPosition(sf::Vector2f(910, 395));

	dimension.setFont(font);
	dimension.setCharacterSize(30);
	dimension.setColor(sf::Color::Black);
	dimension.setString("3x3");
	dimension.setPosition(sf::Vector2f(890, 340));

	///////////////////////players/////////////////////////////////
	player1Indicator.setFont(font);
	player1Indicator.setCharacterSize(30);
	player1Indicator.setColor(sf::Color::Black);
	player1Indicator.setString("Player 1");
	player1Indicator.setPosition(sf::Vector2f(850, 300));

	player2Indicator.setFont(font);
	player2Indicator.setCharacterSize(30);
	player2Indicator.setColor(sf::Color::Black);
	player2Indicator.setString("Player 2");
	player2Indicator.setPosition(sf::Vector2f(850, 350));

	player3Indicator.setFont(font);
	player3Indicator.setCharacterSize(30);
	player3Indicator.setColor(sf::Color::Black);
	player3Indicator.setString("Player 3");
	player3Indicator.setPosition(sf::Vector2f(850, 400));

	player4Indicator.setFont(font);
	player4Indicator.setCharacterSize(30);
	player4Indicator.setColor(sf::Color::Black);
	player4Indicator.setString("Player 4");
	player4Indicator.setPosition(sf::Vector2f(850, 450));
	/////////////////////////////////////////////////////////////////////////

	options.setFont(font);
	options.setCharacterSize(30);
	options.setColor(sf::Color::Black);
	options.setString("Options");
	options.setPosition(sf::Vector2f(870, 440));

	//////////////////////game over text///////////////////////////////////
	sf::Text winner, play_again, yes, no;

	winner.setFont(font); //setting the font
	play_again.setFont(font);
	yes.setFont(font);
	no.setFont(font);

	winner.setCharacterSize(100); //setting the character size in pixels
	winner.setColor(sf::Color::Magenta);
	winner.setPosition(160, 150);

	play_again.setString("Play again?"); //setting the play again string
	play_again.setCharacterSize(100);
	play_again.setColor(sf::Color::Magenta);
	play_again.setPosition(250, 430);

	yes.setString("YES"); //setting the yes string
	yes.setCharacterSize(100);
	yes.setColor(sf::Color::Black);
	yes.setPosition(240, 625);

	no.setString("NO"); //setting the no string
	no.setCharacterSize(100);
	no.setColor(sf::Color::Black);
	no.setPosition(600, 625);
	////////////////////////////////option menu text//////////////////////////////////////
	hostText.setFont(font); //setting the font
	connect.setFont(font);
	quit.setFont(font);
	back.setFont(font);
	number_of_players.setFont(font);
	number_boxes.setFont(font);

	hostText.setString("HOST"); //setting the strings
	back.setString("BACK");
	quit.setString("QUIT");
	connect.setString("CONNECT");
	number_of_players.setString("# of Players");
	number_boxes.setString("2   3   4");

	hostText.setCharacterSize(100); //setting the character size in pixels
	connect.setCharacterSize(100);
	quit.setCharacterSize(100);
	back.setCharacterSize(100);
	number_of_players.setCharacterSize(50);
	number_boxes.setCharacterSize(50);

	hostText.setColor(sf::Color::Magenta); //setting the color
	connect.setColor(sf::Color::Magenta);
	quit.setColor(sf::Color::Magenta);
	back.setColor(sf::Color::Magenta);
	number_of_players.setColor(sf::Color::Magenta);
	number_boxes.setColor(sf::Color::Magenta);

	hostText.setPosition(110, 130); //setting where the text will be drawn on the screen
	connect.setPosition(110, 280);

	number_of_players.setPosition(670, 120);
	number_boxes.setPosition(710, 190);
	////////////////////////////////////////Pause menu text///////////////////////////////
	new_game.setFont(font); //setting the font
	new_game.setString("NEW GAME"); //setting the strings
	new_game.setCharacterSize(100); //setting the character size in pixels
	new_game.setColor(sf::Color::Magenta); //setting the color
	new_game.setPosition(110, 130); //setting where the text will be drawn on the screen

	//*********************************************************************/

	//playing variable, handles program flow
	int playing = 0;
	/******code**********
	0. Main Menu
	1. Playing
	2. Game Over
	3. Paused
	4. Options
	********************/

	//loops while window is open
	while (window.isOpen())
	{
		int tempTurn;
		if (networker.getPlayerID() == 0) {
			tempTurn = gameBoard.getTurn();
			//cout << "The next turn is: " << tempTurn << endl;
		}
		else {
			tempTurn = networker.recieveTurn();
			//cout << "The next turn is: " << tempTurn << endl;
		}
		if (networker.isYourTurn(tempTurn)) {
			//get window events
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					//if window is closed
					window.close();

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //detecting if left mouse button has been pressed
				{
					int x; //x and y hold the mouse's exact pixel position relative to the window with 0,0 being the upper left corner
					int y;
					int x_square; //will hold the x square (0 or 1 or 2) eg, the space that a player can put a piece
					int y_square; //contains the y square(0 or 1 or 2)

								  //gets mouse position and stores in x and y
					x = sf::Mouse::getPosition(window).x;
					y = sf::Mouse::getPosition(window).y;

					//prints out mouse click for debugging purposes
					//cout << x << " , " << y << std::endl;

					//*****************mouse actions main menu******************
					if (playing == 0) {
						//handles slider functionality
						if (((x > 815) && (y > 250)) && ((x < 845) && (y < 530))) {
							int newY = (((y - 240) / 40) * 40) + 235;
							circleMarker.setPosition(sf::Vector2f(815, newY));
							newY = ((y - 240) / 40) + 3;
							gameBoard.setSize(newY);
							dimension.setString(getDimensionString());
						}
						//gets play button click
						if (((x > 875) && (y > 400)) && ((x < 975) && (y < 430))) {
							playing = 1;
							boardCheck.setSize(gameBoard.getSize());
							int tempSize = gameBoard.getSize();
							if (tempSize >= 9) {
								boardCheck.setNeedToWin(5);
							}
							else if (tempSize >= 6) {
								boardCheck.setNeedToWin(4);
							}
							else {
								boardCheck.setNeedToWin(3);
							}
						}
						//gets option button click
						if (((x > 870) && (y > 445)) && ((x < 975) && (y < 475))) {
							playing = 4;
						}
					}
					//**********************************************************/

					//*****************mouse actions during game******************
					if (playing == 1) {
						//handles piece placement during game
						if (((x > 50) && (y > 50)) && ((x < 750) && (y < 750)))
						{
							x_square = ((x - 50) / (700 / gameBoard.getSize()));
							//cout << "The x square to change is : " << x_square << endl;
							y_square = ((y - 50) / (700 / gameBoard.getSize()));
							//cout << "The y square to change is : " << y_square << endl;

							//sets piece on board if no piece exists
								turnCounter++;
								if (networker.getPlayerID() == 0) {
									if (gameBoard.getBoardState(x_square, y_square) == nullptr)
										gameBoard.setBoardState(x_square, y_square);
									networker.sendNewMove(x_square, y_square);
									networker.sendTurn(gameBoard.getTurn());
								}
								else {
									cout << "Position to send: " << x_square << y_square;
									system("pause");
									if (gameBoard.getBoardState(x_square, y_square) == nullptr)
									networker.sendPositionToHost(x_square, y_square);
								}

							//checks if game is over
							if (turnCounter >= (gameBoard.getSize()*gameBoard.getSize())) playing = 2;

							if (boardCheck.hasWon(x_square, y_square, gameBoard.getBoardState(x_square, y_square), &gameBoard)) {
								victor = gameBoard.getBoardState(x_square, y_square)->getIdentifier();
								switch (victor) {
								case 1:
									winner.setString("PLAYER 1 WINS");
									break;
								case 2:
									winner.setString("PLAYER 2 WINS");
									break;
								case 3:
									winner.setString("PLAYER 3 WINS");
									break;
								case 4:
									winner.setString("PLAYER 4 WINS");
									break;
								default:
									winner.setString("NO WINNER!");
									break;
								}
								playing = 2;
							}
						}
						//handles pause button
						if (((x > 930) && (y > 20)) && ((x < 960) && (y < 50))) {
							playing = 3;
						}
					}
					//**********************************************************/

					//*****************mouse actions during game over******************
					if (playing == 2) {
						if (((x > 235) && (y > 649)) && ((x < 425) && (y < 728)))//checks to see if mouse clicked within yes button
						{
							cout << "Yes was clicked" << endl;
							gameBoard.resetBoard();
							playing = 0;
						}
						if (((x > 595) && (y > 650)) && ((x < 729) && (y < 727)))//checks to see if mouse clicked within no button
						{
							cout << "No was clicked" << endl;
							return 0;
						}
					}
					//**************************mouse actions during pause screen********************************/
					if (playing == 3) {
						if (((x > 100) && (y > 150)) && ((x < 670) && (y < 250)))//checks to see if mouse clicked within new_game button
						{
							cout << "New Game was clicked" << endl;
							gameBoard.resetBoard();
							playing = 0;
						}
						if (((x > 100) && (y > 300)) && ((x < 600) && (y < 400)))//checks to see if mouse clicked within quit button
						{
							cout << "Quit was clicked" << endl;
							return 0;
						}
						if (((x > 100) && (y > 450)) && ((x < 600) && (y < 550)))//checks to see if mouse clicked within back button
						{
							cout << "Back was clicked" << endl;
							playing = 1;
						}
					}
					//*****************mouse actions during options******************
					if (playing == 4) {
						if (((x > 100) && (y > 150)) && ((x < 600) && (y < 250)))//checks to see if mouse clicked within host button
						{
							cout << "Started Hosting!" << endl;
							networker.printIP();
							int didStartHosting = networker.startHosting();
							if (didStartHosting > 1) {
								gameBoard.setPlayers(didStartHosting);
								networker.setupGameHost(gameBoard.getPlayers(), gameBoard.getSize());
								playing = 1;
							}
							else {
								playing = 0;
							}

						}
						if (((x > 100) && (y > 300)) && ((x < 600) && (y < 400)))//checks to see if mouse clicked within connect button
						{
							cout << "Started Connecting!" << endl;
							int didConnect = networker.startConnecting();
							if (didConnect == 1) {
								int tempPlayers, tempSize;
								networker.setupClientGame(&tempPlayers, &tempSize);
								gameBoard.setPlayers(tempPlayers);
								gameBoard.setSize(tempSize);
								playing = 1;
							}
							else {
								playing = 0;
							}
						}
						if (((x > 100) && (y > 450)) && ((x < 600) && (y < 550)))//checks to see if mouse clicked within quit button
						{
							cout << "Quit was clicked" << endl;
							return 0;
						}
						if (((x > 100) && (y > 600)) && ((x < 600) && (y < 700)))//checks to see if mouse clicked within back button
						{
							cout << "Back was clicked" << endl;
							playing = 0;
						}
						if (((x > 700) && (y > 200)) && ((x < 750) && (y < 250)))//checks to see if 2 # of players was pressed
						{
							cout << "Two Players was chosen" << endl;
							gameBoard.setPlayers(2);
						}
						if (((x > 770) && (y > 200)) && ((x < 820) && (y < 250)))//checks to see if 3 # of players was pressed
						{
							cout << "Three Players was chosen" << endl;
							gameBoard.setPlayers(3);
						}
						if (((x > 840) && (y > 200)) && ((x < 890) && (y < 250)))//checks to see if 4 # of players was pressed
						{
							cout << "Four Players was chosen" << endl;
							gameBoard.setPlayers(4);
						}
					}
					//**********************************************************/
				}
			}
		}
		else if (networker.getPlayerID() == 0) {
			int newX, newY;
			networker.recievePosition(&newX, &newY);
			networker.sendNewMove(newX, newY);
		}
		else {
			int newX, newY;
			networker.recieveNewMove(&newX, &newY);
			gameBoard.setBoardState(newX, newY);
		}

		//set background to white
		window.clear(sf::Color::White);

		//handles conditional drawing

		if (playing == 0 || playing == 4) {			//main menu
			window.draw(sizeSelector);
			window.draw(circleMarker);
			window.draw(playButton);
			window.draw(play);
			window.draw(dimension);
			window.draw(options);
		}
		else if (playing == 1 || playing == 2 || playing == 3 || playing == 4) {	//playing game
			window.draw(player1Indicator);
			window.draw(player2Indicator);

			if (gameBoard.getPlayers() == 3) {
				window.draw(player3Indicator);
			}
			else if (gameBoard.getPlayers() == 4) {
				window.draw(player3Indicator);
				window.draw(player4Indicator);
			}

			playerIndicator.setPosition(sf::Vector2f(820, (310 + (gameBoard.getTurn() * 50))));
			window.draw(playerIndicator);

			window.draw(pause1);
			window.draw(pause2);
		}
		else if (playing == 2) {	//game over

		}
		else if (playing == 3) {	//paused game

		}
		else if (playing == 4) {	//options menu

		}



		//draws the board based on the rectangles generated in HBoard and VBoard and the size of the board
		for (int i = 0; i < gameBoard.getSize() - 1; i++) {
			window.draw(*(gameBoard.getHBoard(i)));
			window.draw(*(gameBoard.getVBoard(i)));
		}

		//draws sprites in the correct location based on boardState array
		for (int i = 0; i < gameBoard.getSize(); i++) {
			for (int j = 0; j < gameBoard.getSize(); j++) {
				if (gameBoard.getBoardState(i, j) != nullptr) {
					sf::Sprite temp = gameBoard.getBoardState(i, j)->getSprite();
					window.draw(gameBoard.getBoardState(i, j)->getSprite());
				}
			}
		}

		//draws mask for pause, game over, and options
		if (playing == 2 || playing == 3 || playing == 4) {
			window.draw(mask);
			if (playing == 2) {
				window.draw(button_background);
				window.draw(button_background2);
				window.draw(yes);
				window.draw(no);
				window.draw(winner);
				window.draw(play_again);
			}
			if (playing == 3)
			{
				quit.setPosition(110, 280);
				back.setPosition(110, 430);
				window.draw(new_game_button);
				window.draw(quit_button);
				window.draw(connect_button);
				window.draw(new_game);
				window.draw(quit);
				window.draw(back);
			}
			if (playing == 4) {
				quit.setPosition(110, 430);
				back.setPosition(110, 580);
				window.draw(host_button); //THE BUTTON BACKGROUNDS MUST BE DRAWN BEFORE THE TEXT
				window.draw(connect_button);//otherwise the text will be "behind" the button and not visible
				window.draw(quit_button);
				window.draw(back_button);
				window.draw(two_player_button);
				window.draw(three_player_button);
				window.draw(four_player_button);
				window.draw(connect);
				window.draw(hostText);
				window.draw(quit);
				window.draw(back);
				window.draw(number_of_players);
				window.draw(number_boxes);
			}
		}

		//displays window
		window.display();
	}
}

//changes string on main menu based on board size
string Game::getDimensionString() {
	switch (gameBoard.getSize()) {
	case 3:
		return "3x3";
	case 4:
		return "4x4";
	case 5:
		return "5x5";
	case 6:
		return "6x6";
	case 7:
		return "7x7";
	case 8:
		return "8x8";
	case 9:
		return "9x9";
	case 10:
		return "10x10";
	default:
		return "3x3";
	}
}
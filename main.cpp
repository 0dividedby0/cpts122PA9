#include "Game.h"
#include <SFML/Graphics.hpp>

void main() {

	Game newGame;
	newGame.startGame();

}

//Piece *boardState[10][10];
//Piece oPiece;
//Piece xPiece;
//
//boardState[3][5] = &oPiece;
//boardState[1][6] = &oPiece;
//
//sf::RectangleShape lines[9];
//
//lines[0] = sf::RectangleShape(sf::Vector2f(450, 10));
//lines[0].setFillColor(sf::Color::Red);
//lines[0].setPosition(sf::Vector2f(175, 225));
//
////main window
//sf::RenderWindow window(sf::VideoMode(800, 600), "Tic Tac Twist");
//
////rectangles for grid
//sf::RectangleShape line1(sf::Vector2f(450, 10));
//line1.setFillColor(sf::Color::Red);
//line1.setPosition(sf::Vector2f(175, 225));
//
//sf::RectangleShape line2(sf::Vector2f(450, 10));
//line2.setFillColor(sf::Color::Red);
//line2.setPosition(sf::Vector2f(175, 375));
//
//sf::RectangleShape line3(sf::Vector2f(10, 450));
//line3.setFillColor(sf::Color::Red);
//line3.setPosition(sf::Vector2f(325, 75));
//
//sf::RectangleShape line4(sf::Vector2f(10, 450));
//line4.setFillColor(sf::Color::Red);
//line4.setPosition(sf::Vector2f(475, 75));
//
////marker
//sf::CircleShape circleMarker(20);
//circleMarker.setFillColor(sf::Color::Green);
//circleMarker.setPosition(sf::Vector2f(175, 75));
//
//while (window.isOpen())
//{
//	//get window events
//	sf::Event event;
//	while (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			//if window is closed
//			window.close();
//
//		if (event.type == sf::Event::KeyPressed) {
//			if (event.key.code == sf::Keyboard::Num1) {
//			}
//		}
//	}
//
//	window.clear(sf::Color::White);
//	window.draw(lines[0]);
//	window.draw(line2);
//	window.draw(line3);
//	window.draw(line4);
//	window.draw(circleMarker);
//	window.display();
//}
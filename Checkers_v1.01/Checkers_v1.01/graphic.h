#include "AI.h"
#include "SFML\include\SFML\Graphics.hpp"


class Graphic : public AI
{
public:
	Graphic();
	~Graphic();
	void run() {
		sf::RenderWindow window(sf::VideoMode(800, 800), "Ckeckers");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)) {
					cout << "MouseClicked" << endl;
					mouseClicked = sf::Mouse::getPosition(window);
				}
				if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left)) {
					cout << "X = " << mouseClicked.x / 100 << endl;
					cout << "Y = " << 7 - (mouseClicked.y / 100) << endl;
					cout << "W = " << sf::Mouse::getPosition(window).x / 100 << endl;
					cout << "X = " << 7 - (sf::Mouse::getPosition(window).y / 100) << endl;
					cout << "MouseRealeased" << endl;

					Board::moveTo(mouseClicked.x / 100, (7 - mouseClicked.y / 100), sf::Mouse::getPosition(window).x / 100, 7 - (sf::Mouse::getPosition(window).y / 100));
					AI::board.moveTo(mouseClicked.x / 100, (7 - mouseClicked.y / 100), sf::Mouse::getPosition(window).x / 100, 7 - (sf::Mouse::getPosition(window).y / 100));
					movements();
					displayCoord();
					clearMovements();
					AI::board.Display();
				}

			} //while
			window.clear(sf::Color(255, 255, 255));
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (((i + j) % 2) == 1) {
						continue;
					}
					else if (Board::board[i][j] == EMPTY) {
						_field.setTexture(_EMPTY);
					}
					else if (Board::board[i][j] == BLACK) {
						_field.setTexture(_BLACK);
					}
					else if (Board::board[i][j] == WHITE) {
						_field.setTexture(_WHITE);
					}
					else if (Board::board[i][j] == BLACK_K) {
						_field.setTexture(_BLACK_K);
					}
					else if (Board::board[i][j] == WHITE_K) {
						_field.setTexture(_WHITE_K);
					}
					else {
						continue;
					}
					_field.setPosition(sf::Vector2f::Vector2(i * 100.0, 700.0 - j * 100.0));
					window.draw(_field);

				}
			}
			window.display();
		} //while
	}
private:
	sf::Texture _WHITE_K, _WHITE, _BLACK, _BLACK_K, _EMPTY;
	sf::Sprite _field;
	sf::Vector2i mouseClicked;
};



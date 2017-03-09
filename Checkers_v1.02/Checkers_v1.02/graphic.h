#include "GameCtrl.h"

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !GRAPHIC_HPP



class Graphic
{
public:
	Graphic();
	~Graphic();
	void run() {
		int frame = 0;
		sf::RenderWindow window(sf::VideoMode(800, 800), "Ckeckers");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
					mouseClicked = sf::Mouse::getPosition(window);
				if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left)) {
					gameCtrl->move(mouseClicked.x / 100, (7 - mouseClicked.y / 100), sf::Mouse::getPosition(window).x / 100, 7 - (sf::Mouse::getPosition(window).y / 100));
				}

				//	AI::Board::moveTo(mouseClicked.x / 100, (7 - mouseClicked.y / 100), sf::Mouse::getPosition(window).x / 100, 7 - (sf::Mouse::getPosition(window).y / 100));
				//	system("CLS"); 
				//	frame++;
				//	vector<Coord> AIresult;
				//	if (frame % 2 == 1) {
				//		AI::Board::Display();
				//		cout << "BLACK:  " << endl;
				//		AIresult = AI::getSolution(CAVITY, P_BLACK);
				//		for (auto & it : AIresult) {
				//			moveTo(it.x, it.y, it.x_, it.y_);
				//		}
				//	}
				//	else {
				//		cout << "WHITE: " << endl;
				//		AIresult = AI::getSolution(CAVITY, P_WHITE);
				//		for (auto & it : AIresult) {
				//			moveTo(it.x, it.y, it.x_, it.y_);
				//		}
				//	}					
				//}
			}
			window.clear(sf::Color(255, 255, 255));
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (((i + j) % 2) == 1) {
						continue;
					}
					else if (board->getField(i, j) == EMPTY) _field.setTexture(_EMPTY);
					else if (board->getField(i, j) == BLACK) _field.setTexture(_BLACK);
					else if (board->getField(i, j) == WHITE) _field.setTexture(_WHITE);
					else if (board->getField(i, j) == BLACK_K) _field.setTexture(_BLACK_K);
					else if (board->getField(i, j) == WHITE_K) _field.setTexture(_WHITE_K);
					else continue;

					_field.setPosition(sf::Vector2f::Vector2(i * 100.0f, 700.0f - j * 100.0f));
					window.draw(_field);

				}
			}
			window.display();
			Sleep(10);
		}
	}
private:
	sf::Texture _WHITE_K, _WHITE, _BLACK, _BLACK_K, _EMPTY;
	sf::Sprite _field;
	sf::Vector2i mouseClicked;
	Board * board;
	GameCtrl * gameCtrl;
};



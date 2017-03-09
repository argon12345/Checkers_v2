#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !GRAPHIC_HPP

#ifndef AI_H
#define AI_H
#include "AI.h"
#endif // !AI_H



class ViewGame
{
public:
	ViewGame();
	~ViewGame();

private:

};

ViewGame::ViewGame()
{
}

ViewGame::~ViewGame()
{
}




class View
{
public:
	View();
	~View();

private:
	sf::Texture _WHITE_K, _WHITE, _BLACK, _BLACK_K, _EMPTY;
	sf::Sprite _field;
	sf::Vector2i mouseClicked;
};


#include "AI.h"
#include "SFML\Graphics.hpp"


class Graphic : public AI
{
public:
	Graphic();
	~Graphic();
	void run();
private:
	sf::Texture _WHITE_K, _WHITE, _BLACK, _BLACK_K, _EMPTY;
	sf::Sprite _field;
	sf::Vector2i mouseClicked;
};



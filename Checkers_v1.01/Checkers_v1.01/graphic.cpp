#include "graphic.h"


Graphic::Graphic()
	:AI(Board())
{
	_WHITE_K.loadFromFile("black_field_w_k.bmp");
	_WHITE.loadFromFile("black_field_w.bmp");
	_BLACK.loadFromFile("black_field_b.bmp");
	_BLACK_K.loadFromFile("black_field_b_k.bmp");
	_EMPTY.loadFromFile("black_field.bmp");
}

Graphic::~Graphic() {
}


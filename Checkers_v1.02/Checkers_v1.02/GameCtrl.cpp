#include "GameCtrl.h"


GameCtrl::GameCtrl()
{
	this->board = new Board();
}

GameCtrl::GameCtrl(Board * board)
	:board(board)
{

}

GameCtrl::~GameCtrl()
{
}

bool GameCtrl::move(int x, int y, int z, int w)
{
	bool moveWithBeating = board->checkBeating(x, y);
	// Sprawdzenie czy pionek nale¿y do gracza
	if (board->getField(x, y) == WHITE || board->getField(x, y) == WHITE_K) {
		// Sprawdzenie czy dany ruch mo¿e zostaæ wykonany
		if (board->checkMoveTo(x, y, z, w)) {
			if (board->moveTo(x, y, z, w)) {
				if (board->checkBeating(z, w) && moveWithBeating) {
					return true;
				}
				else {
					if (AIMove()) {
						return true;
					}
					else {
						return false;
					}
				}
				return true;
			}
			else {
				cout << "GameCtrl - Ruch nie zosta³ wykonany" << endl;
				return false;
			}

		}
		else {
			cout << "GameCtrl - Ruch nie moze zostac wykonany" << endl;
			return false;
		}
	}
	else {
		cout << "GameCtrl - Wskazany pionek nie nale¿y do gracza" << endl;
		return false;
	}

}

bool GameCtrl::AIMove()
{
	ai = new AI(*this->board);
	vector<Coord> AIresult = ai->getSolution(8, P_BLACK);
	for (auto & it : AIresult) {
		if (!board->moveTo(it.x, it.y, it.x_, it.y_)) {
			cout << "GameCtrl - Blad sztucznej inteligencji" << endl;
			cout << "Z  " << it.x << " " << it.y << endl;
			cout << "Do " << it.x_ << " " << it.y_ << endl;
		}

	}
	return true;
}

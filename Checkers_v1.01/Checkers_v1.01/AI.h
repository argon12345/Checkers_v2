#include "Board.h"
#include <vector>
#include <cstdio>
#include <ctime>
#include <Windows.h>

#define CAVITY 4

struct Coord{
	int x, y, x_, y_;
	Coord(int x, int y, int x_, int y_){
		this->x = x;
		this->y = y;
		this->x_ = x_;
		this->y_ = y_;
	}
};

class AI : public Board
{
public:
	AI(Coord, int, Board);
	AI(Board);
	AI();
	void movements();
	void movementWithBeatings(int, int);
	void movementWithoutBeatings(int, int);
	void clearMovements();
	void rating(PLAYER);
	int getValue();
	void displayCoord();
	Board board;
private:
	int value, cavity;
	vector<AI*> node;
	vector<vector<Coord> > _coord;

	PLAYER player, opponent;
};

#include <iostream>
#include <cstdlib>

using namespace std;

enum FIELD{
	WHITE_K = -2,
	WHITE = -1,
	EMPTY = 0,
	BLACK = 1,
	BLACK_K = 2
};

enum PLAYER{
	P_WHITE = -1,
	P_BLACK = 1
};

class Board {
public:
	Board();
	~Board();
	Board(const Board & board);
	bool checkMoveTo(int, int, int, int);
	bool checkBeatings(PLAYER);
	bool checkBeating(int,int);
	bool moveTo(int, int, int, int);
	void promotion(int, int);
	void Display();
	FIELD getField(int, int);

protected:
	FIELD board[8][8];
};


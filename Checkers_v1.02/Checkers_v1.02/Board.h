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

	// Konstruktor kopiujacy
	Board(const Board & board);

	// Sprawdzenie czy dany ruch jest dozwolony
	bool checkMoveTo(int, int, int, int);

	// Sprawdzenie czy gracz ma bicia
	bool checkBeatings(PLAYER);

	// Sprawdzenie czy z danego pola jest bicie
	bool checkBeating(int,int);

	// Przemieszczanie pionka
	bool moveTo(int, int, int, int);

	// Awansowanie pionka na dame
	void promotion(int, int);

	// Degradacja damy na pionka
	void unPromotion(int, int);

	// Zamiana planszy
	void reverse();

	// Wyswietlenie planszy
	void Display();

	// Zwraca typ pola na planszy
	FIELD getField(int, int);

protected:
	FIELD board[8][8];
};


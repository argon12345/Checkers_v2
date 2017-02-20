#include "Board.h"
#include <vector>
#include <cstdio>
#include <ctime>
#include <Windows.h>

#define CAVITY 4

struct Coord {
	int x, y, x_, y_;
	Coord(int x, int y, int x_, int y_) {
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

	// Zwraca najlepszy mo¿liwy ruch
	vector <Coord> getSolution(int);

	// Tworzenie wektora mo¿liwych ruchów
	void movements();

	// Tworzenie wektora ruchów z biciem
	void movementWithBeatings(int, int, int, vector <Coord> &);

	// Tworzenie wektora ruchów bez bicia
	void movementWithoutBeatings(int, int, int);

	// Czyszczenie wektora ruchów
	void clearMovements();

	// Funkcja oceniaj¹ca sytuacje na planszy
	void rating(PLAYER);

	// Zwraca wartoœæ oceny sytuacji na planszy
	int getValue();

	// Wyœwietlenie mo¿liwych aktualnie ruchów
	void displayCoord();

	int treeMinMax(vector <Coord>, int);
private:
	inline void movementsWithBeatingsFromTo(int i, int j, int x, int y, int step, vector <Coord>);
	inline void movementsWithBeatingsFromToQueen(int i, int j, int x, int y, int m, int n, int step, vector <Coord>);
	

	// Przechowuje ocene sytuacji 
	int value;

	// Poziom zag³ebienia rekurencji.
	int cavity;

	int movement;

	//
	vector<int> nodeValue;

	//
	vector<vector<Coord> > _coord;

	//
	PLAYER player, opponent;
};

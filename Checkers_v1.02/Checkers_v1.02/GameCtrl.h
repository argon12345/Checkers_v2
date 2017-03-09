#include "AI.h"



class GameCtrl
{
public:
	GameCtrl();
	GameCtrl(Board * board);
	~GameCtrl();

	// Sprawdza czy dany ruch mo¿e zostaæ wykonany
	bool move(int, int, int, int);
private:
	bool AIMove();


	Board * board;
	AI * ai;
};


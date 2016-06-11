#include "Board.h"
#include <vector>
#include <cstdio>
#include <ctime>
#include <Windows.h>

struct minMaxTree {


};

class AI2 : public Board
{
public:
	AI2();
	~AI2();
	AI2(Board board, int cavity);
private:
	int cavity;
};


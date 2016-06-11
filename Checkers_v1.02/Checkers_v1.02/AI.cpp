#include "AI.h"


AI::AI(Coord coord, int cavity, Board board)
	:Board(board)
{
	Board::moveTo(coord.x, coord.y, coord.x_, coord.y_);
	this->cavity = cavity + 1;
	if ((cavity % 2) == 1) {
		player = P_BLACK;
	}
	else {
		player = P_WHITE;
	}
}
AI::AI(Board board)
	:Board(board)
{

	cavity = 0;
	player = P_WHITE;
}
AI::AI() {

}

void AI::movements() {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			movementWithBeatings(i, j, 0);
		}
	}
	if (_coord.size() == 0) {
		for (size_t i = 0; i < 8; i++) {
			for (size_t j = 0; j < 8; j++) {
				movementWithoutBeatings(i, j, 0);
			}
		}
	}
}


void AI::movementWithBeatings(int i, int j, int step = 0) {
	//Done 100%
	int counter = 0;
	if (Board::board[i][j] == player) {
		if (player == P_WHITE) {
			if ((i < 6 && j < 6) && (Board::board[i + 2][j + 2] == EMPTY) && (Board::board[i + 1][j + 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i + 2, j + 2, step);
				}
				else {
					counter++;
					vector <Coord> temp;
					temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i + 2, j + 2, step);
				}
			}
			if ((i < 6 && j > 1) && (Board::board[i + 2][j - 2] == EMPTY) && (Board::board[i + 1][j - 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i + 2, j - 2, step);
				}
				else {
					counter++;
					vector <Coord> temp;
					temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i + 2, j - 2, step);
				}
			}
			if ((i > 1 && j < 6) && (Board::board[i - 2][j + 2] == EMPTY) && (Board::board[i - 1][j + 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i - 2, j + 2, step);
				}
				else {
					counter++;
					vector <Coord> temp;
					temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i - 2, j + 2, step);
				}
			}
			if ((i > 1 && j > 1) && (Board::board[i - 2][j - 2] == EMPTY) && (Board::board[i - 1][j - 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i - 2, j - 2, step);
				}
				else {
					counter++;
					vector <Coord> temp;
					temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i - 2, j - 2, step);
				}
			}
		}
		else {
			if ((i < 6 && j < 6) && (Board::board[i + 2][j + 2] == EMPTY) && (Board::board[i + 1][j + 1] < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
			}
			if ((i < 6 && j > 1) && (Board::board[i + 2][j - 2] == EMPTY) && (Board::board[i + 1][j - 1] < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j - 2));
			}
			if ((i > 1 && j < 6) && (Board::board[i - 2][j + 2] == EMPTY) && (Board::board[i - 1][j + 1] < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j + 2));
			}
			if ((i > 1 && j > 1) && (Board::board[i - 2][j - 2] == EMPTY) && (Board::board[i - 1][j - 1] < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j - 2));
			}
		}
	}
	//TODO
	if (Board::board[i][j] == player * 2) {
		for (int k = 1, l = 1; i + k < 6 && j + l < 6; k++, l++) {
			if (Board::board[i + k][j + l] == EMPTY) {
				cout << "Damka1 " << i + k << " " << j + l << endl;
				continue;
			}

			if ((Board::board[i + k][j + l] == player * -1) || (Board::board[i + k][j + l] == player * -2)) {

				int posEx = i + k;
				int posEy = j + l;
				int steptemp = step;
				for (int m = 1, n = 1; i + k + m < 8 && j + l + n < 8; m++, n++) {
					cout << " >> " << endl;
					if (Board::board[i + k + m][j + l + n] == EMPTY) {
						step--;
						cout << "Damka2 " << i + k + m << " " << j + l + n << endl;
						if (counter == 0) {							
							movementsWithBeatingsFromToQueen(i, j, i + k + m, j + l + n, posEx, posEy, step);
						}
						else {
							cout << "TFW" << endl;
							vector <Coord> temp;
							temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
							_coord.push_back(temp);
							movementsWithBeatingsFromToQueen(i, j, i + k + m, j + l + n, posEx, posEy, step);
						}
					}
				}
				step = steptemp;
				break;
			}
			else {
				break;
			}
		}
	}
}
void AI::movementWithoutBeatings(int i, int j, int step = 0) {
	if (Board::board[i][j] == player) {
		if (player == P_WHITE) {
			if (((i < 7) && (j < 7)) && (Board::board[i + 1][j + 1] == EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 1, j + 1));
			}
			if (((i > 0) && (j < 7)) && Board::board[i - 1][j + 1] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 1, j + 1));
			}
		}
		else {
			if (((i < 7) && (j > 0)) && Board::board[i + 1][j - 1] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 1, j - 1));
			}
			if (((i > 0) && (j > 0)) && Board::board[i - 1][j - 1] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 1, j - 1));
			}
		}
	}
	if (Board::board[i][j] == player * 2) {
		for (int k = 1, l = 1; k + i < 8 && l + i < 8; k++, l++) {
			if (board[i + k][j + l] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + k, j + l));
			}
			else {
				break;
			}

		}
		for (int k = 1, l = 1; k + i < 8 && j - l >= 0; k++, l++) {
			if (board[i + k][j - l] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + k, j - l));
			}
			else {
				break;
			}

		}
		for (int k = 1, l = 1; i - k >= 0 && l + i < 8; k++, l++) {
			if (board[i - k][j + l] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - k, j + l));
			}
			else {
				break;
			}

		}
		for (int k = 1, l = 1; i - k >= 0 && i - l >= 0; k++, l++) {
			if (board[i - k][j - l] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - k, j - l));
			}
			else {
				break;
			}

		}
	}
}
void AI::clearMovements() {
	_coord.clear();
}
void AI::rating(PLAYER player) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Board::board[i][j] == EMPTY) {
				continue;
			}
			else {
				if (Board::board[i][j] == player) {
					value++;
				}
				else if (Board::board[i][j] == player * 2) {
					value += 10;
				}
				else if (Board::board[i][j] == player * -1) {
					value--;
				}
				else if (Board::board[i][j] == player * -2) {
					value -= 10;
				}
			}
		}
	}
}
int AI::getValue() {
	return value;
}
void AI::displayCoord() {
	for (size_t i = 0; i < _coord.size(); i++) {
		for (size_t j = 0; j < _coord[i].size(); j++) {
			cout << _coord[i][j].x << "," << _coord[i][j].y << " do " << _coord[i][j].x_ << "," << _coord[i][j].y_ << " || ";
		}
		cout << endl;
	}
}
inline void AI::movementsWithBeatingsFromTo(int i, int j, int x, int y, int step) {
	if (step == 0) {
		cout << "SDFASDFASDFADSFASDFDSFAFDFDS" << endl;
		// Tworzenie nowego wêz³a
		vector<Coord> temp2;
		temp2.push_back(Coord(i, j, x, y));
		_coord.push_back(temp2);

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[(i + x) / 2][(j + y) / 2];
		Board::board[(i + x) / 2][(j + y) / 2] = EMPTY;
		Board::board[i][j] = EMPTY;

		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		movementWithBeatings(x, y, step + 1);

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[(i + x) / 2][(j + y) / 2] = temp;

	}
	else {
		_coord[_coord.size() - 1].push_back(Coord(i, j, x, y));

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[(i + x) / 2][(j + y) / 2];
		Board::board[(i + x) / 2][(j + y) / 2] = EMPTY;
		Board::board[i][j] = EMPTY;

		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		movementWithBeatings(x, y, step + 1);

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[(i + x) / 2][(j + y) / 2] = temp;
	}

}
inline void AI::movementsWithBeatingsFromToQueen(int i, int j, int x, int y, int m, int n, int step) {
	if (step == 0) {

		// Tworzenie nowego wêz³a
		vector<Coord> temp2;
		temp2.push_back(Coord(i, j, x, y));
		_coord.push_back(temp2);

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[m][n];
		Board::board[m][n] = EMPTY;
		Board::board[i][j] = EMPTY;
		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		movementWithBeatings(x, y, step + 1);

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[m][n] = temp;

	}
	else {
		_coord[_coord.size() - 1].push_back(Coord(i, j, x, y));

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[m][n];
		Board::board[m][n] = EMPTY;
		Board::board[i][j] = EMPTY;

		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		movementWithBeatings(x, y, step + 1);

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[m][n] = temp;
	}
}

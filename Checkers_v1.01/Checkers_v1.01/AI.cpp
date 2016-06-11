#include "AI.h"


AI::AI(Coord coord, int cavity, Board board) {
	this->board = Board(board);
	this->board.moveTo(coord.x, coord.y, coord.x_, coord.y_);
	this->cavity = cavity + 1;
	if ((cavity % 2) == 1) {
		player = P_BLACK;
	}
	else {
		player = P_WHITE;
	}
}
AI::AI(Board board) {
	this->board = Board(board);
	this->cavity = 0;
	player = P_WHITE;
}
AI::AI() {

}

void AI::movements() {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			movementWithoutBeatings(i, j);
			movementWithBeatings(i, j);
		}
	}
}
void AI::movementWithBeatings(int i, int j) {
	if (board.getField(i, j) == player) {
		if (player == P_WHITE) {
			if ((i < 6 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i + 1, j + 1) > EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
			}
			if ((i < 6 && j > 1) && (board.getField(i + 2, j - 2) == EMPTY) && (board.getField(i + 1, j - 1) > EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j - 2));
			}
			if ((i > 1 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i - 1, j + 1) > EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
			}
			if ((i > 1 && j > 1) && (board.getField(i - 2, j - 2) == EMPTY) && (board.getField(i - 1, j - 1) > EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j - 2));
			}
		}
		else {
			if ((i < 6 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i + 1, j + 1) < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
			}
			if ((i < 6 && j > 1) && (board.getField(i + 2, j - 2) == EMPTY) && (board.getField(i + 1, j - 1) < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j - 2));
			}
			if ((i > 1 && j < 6) && (board.getField(i + 2, j + 2) == EMPTY) && (board.getField(i - 1, j + 1) < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
			}
			if ((i > 1 && j > 1) && (board.getField(i - 2, j - 2) == EMPTY) && (board.getField(i - 1, j - 1) < EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j - 2));
			}
		}
	}
	if (board.getField(i, j) == player * 2) {

	}
}
void AI::movementWithoutBeatings(int i, int j) {
	if (board.getField(i, j) == player) {
		if (player == P_WHITE) {
			if (((i < 7) && (j < 7)) && (board.getField(i + 1, j + 1) == EMPTY)) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 1, j + 1));
			}
			if (((i > 0) && (j < 7)) && board.getField(i - 1, j + 1) == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 1, j + 1));
			}
		}
		else {
			if (((i < 7) && (j > 0)) && board.getField(i + 1, j - 1) == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i + 1, j - 1));
			}
			if (((i > 0) && (j > 0)) && board.getField(i - 1, j - 1) == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - 1, j - 1));
			}
		}
	}
	if (board.getField(i, j) == player * 2) {

	}
}

void AI::clearMovements() {
	_coord.clear();
}

void AI::rating(PLAYER player) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board.getField(i, j) == EMPTY) {
				continue;
			}
			else {
				if (board.getField(i, j) == player) {
					value++;
				}
				else if (board.getField(i, j) == player * 2) {
					value += 10;
				}
				else if (board.getField(i, j) == player * -1) {
					value--;
				}
				else if (board.getField(i, j) == player * -2) {
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
			cout << i << "z " << _coord[i][j].x << "," << _coord[i][j].y << " do " << _coord[i][j].x_ << "," << _coord[i][j].y_ << endl;
		}
	}
}
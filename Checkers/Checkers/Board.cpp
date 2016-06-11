#include "Board.h"


bool Board::checkBeatings(PLAYER player) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j += 2) {
			if ((board[i][j] == player) || (board[i][j] == (player * 2))) {
				if (checkBeating(i, j)) {
					return true;
				}
			}
		}
		i++;
		for (int j = 1; j < 8; j += 2) {
			if ((board[i][j] == player) || (board[i][j] == (player * 2))) {
				if (checkBeating(i, j)) {
					return true;
				}
			}
		}
	}
	return false;
}
bool Board::checkBeating(int x, int y) {
	FIELD enemy = (board[x][y] > 0 ? WHITE : BLACK);
	if (abs(board[x][y]) == 1) {
		if (x < 6 && y < 6 && ((board[x + 1][y + 1] == enemy) || (board[x + 1][y + 1] == 2 * enemy)) && board[x + 2][y + 2] == EMPTY) {
			cout << "x = " << x << " y = " << y << "Bicie nr:  1" << endl;
			return true;
		}
		if (x < 6 && y > 1 && ((board[x + 1][y - 1] == enemy) || (board[x + 1][y - 1] == 2 * enemy)) && board[x + 2][y - 2] == EMPTY) {
			cout << "x = " << x << " y = " << y << "Bicie nr:  2" << endl;
			return true;
		}
		if (x > 1 && y > 1 && ((board[x - 1][y - 1] == enemy) || (board[x - 1][y - 1] == 2 * enemy)) && board[x - 2][y - 2] == EMPTY) {
			cout << "x = " << x << " y = " << y << "Bicie nr:  3" << endl;
			return true;
		}
		if (x > 1 && y < 6 && ((board[x - 1][y + 1] == enemy) || (board[x - 1][y + 1] == 2 * enemy)) && board[x - 2][y + 2] == EMPTY) {
			cout << "x = " << x << " y = " << y << "Bicie nr: 4 " << endl;
			return true;
		}
	}
	else if (abs(board[x][y]) == 2) {
		for (int i = x + 1, j = y + 1; (i <= 6) && (j <= 6); i++, j++) {
			if ((board[i][j] == enemy || board[i][j] == 2 * enemy) && board[i + 1][j + 1] == EMPTY) {
				cout << "x = " << x << " y = " << y << "Bicie nr:  5" << endl;
				return true;
			}
			else if (board[i][j] == EMPTY){
				continue;
			}
			else{
				break;
			}
		}
		for (int i = x - 1, j = y + 1; (i >= 1) && (j <= 6); i--, j++) {
			if ((board[i][j] == enemy || board[i][j] == 2 * enemy) && board[i - 1][j + 1] == EMPTY) {
				cout << "x = " << x << " y = " << y << "Bicie nr:  6" << endl;
				return true;
			}
			else if (board[i][j] == EMPTY){
				continue;
			}
			else{
				break;
			}
		}
		for (int i = x + 1, j = y - 1; (i <= 6) && (j >= 1); i++, j--) {
			if ((board[i][j] == enemy || board[i][j] == 2 * enemy) && board[i + 1][j - 1] == EMPTY) {
				cout << "x = " << x << " y = " << y << "Bicie nr:  7" << endl;
				return true;
			}
			else if (board[i][j] == EMPTY){
				continue;
			}
			else{
				break;
			}
		}
		for (int i = x - 1, j = y - 1; (i >= 1) && (j >= 1); i--, j--) {
			if ((board[i][j] == enemy || board[i][j] == 2 * enemy) && board[i - 1][j - 1] == EMPTY) {
				cout << "x = " << x << " y = " << y << "Bicie nr:  8" << endl;
				return true;
			}
			else if (board[i][j] == EMPTY){
				continue;
			}
			else{
				break;
			}
		}
	}
	return false;
} // Done 100%
bool Board::checkMoveTo(int x, int y, int x_, int y_) {
	FIELD var = board[x][y];
	if (x >= 0 && y >= 0 && x_ >= 0 && y_ >= 0 && x < 8 && y < 8 && x_ < 8 && y_ < 8 && x != x_ && y != y_ && (abs(x - x_) == abs(y - y_))) {
		if (var == WHITE) {
			if (((y_ - y) == 1) && (abs(x - x_) == 1) && board[x_][y_] == EMPTY)
				return true;
			if ((abs(y_ - y) == 2) && (abs(x - x_) == 2) && board[x_][y_] == EMPTY && (board[(x + x_) / 2][(y + y_) / 2] == BLACK || board[(x + x_) / 2][(y + y_) / 2] == BLACK_K))
				return true;
			return false;
		}
		else if (var == BLACK) {
			if (((y_ - y) == -1) && (abs(x - x_) == 1) && board[x_][y_] == EMPTY) return true;
			if ((abs(y_ - y) == 2) && (abs(x - x_) == 2) && board[x_][y_] == EMPTY && (board[(x + x_) / 2][(y + y_) / 2] == WHITE || board[(x + x_) / 2][(y + y_) / 2] == WHITE_K))
				return true;
			return false;
		}
		else if (var == WHITE_K) {
			if (x < x_) {
				if (y < y_) {
					//+/+
					for (int i = x + 1, j = y + 1; (i < x_) && (j < y_); i++, j++) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == BLACK || board[i][j] == BLACK_K) {
							for (int k = i + 1, g = j + 1; (k <= x_) && (g <= y_); k++, g++) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
				else {
					//+\-
					for (int i = x + 1, j = y - 1; (i < x_) && (j > y_); i++, j--) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == BLACK || board[i][j] == BLACK_K) {
							for (int k = i + 1, g = j - 1; (k <= x_) && (g >= y_); k++, g--) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
			}
			else {
				if (y < y_) {
					//-/+
					for (int i = x - 1, j = y + 1; (i > x_) && (j < y_); i--, j++) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == BLACK || board[i][j] == BLACK_K) {
							for (int k = i - 1, g = j + 1; (k >= x_) && (g <= y_); k--, g++) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
				else {
					//-\-
					for (int i = x - 1, j = y - 1; (i > x_) && (j > y_); i--, j--) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == BLACK || board[i][j] == BLACK_K) {
							for (int k = i - 1, g = j - 1; (k >= x_) && (g >= y_); k--, g--) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
		else if (var == BLACK_K) {
			if (x < x_) {
				if (y < y_) {
					//+/+
					for (int i = x + 1, j = y + 1; (i < x_) && (j < y_); i++, j++) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == WHITE || board[i][j] == WHITE_K) {
							for (int k = i + 1, g = j + 1; (k <= x_) && (g <= y_); k++, g++) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
				else {
					//+\-
					for (int i = x + 1, j = y - 1; (i < x_) && (j > y_); i++, j--) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == WHITE || board[i][j] == WHITE_K) {
							for (int k = i + 1, g = j - 1; (k <= x_) && (g >= y_); k++, g--) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
			}
			else {
				if (y < y_) {
					//-/+
					for (int i = x - 1, j = y + 1; (i > x_) && (j < y_); i--, j++) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == WHITE || board[i][j] == WHITE_K) {
							for (int k = i - 1, g = j + 1; (k >= x_) && (g <= y_); k--, g++) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
				else {
					//-\-
					for (int i = x - 1, j = y - 1; (i > x_) && (j > y_); i--, j--) {
						if (board[i][j] == EMPTY) {
							continue;
						}
						else if (board[i][j] == WHITE || board[i][j] == WHITE) {
							for (int k = i - 1, g = j - 1; (k >= x_) && (g >= y_); k--, g--) {
								if (board[k][g] != EMPTY) {
									return false;
								}
							}
							return true;
						}
						else {
							return false;
						}
					}
					if (board[x_][y_] == EMPTY){
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
	}
	return false;
}
bool Board::moveTo(int x, int y, int x_, int y_) {
	PLAYER player;
	(board[x][y] < 0) ? player = P_WHITE : player = P_BLACK;
	if (checkMoveTo(x, y, x_, y_)) {
		cout << "moveTo - etap 1" << endl;
		if ((abs(board[x][y]) == 1) && (abs(x - x_) == 1) && !checkBeatings(player)) {
			cout << "moveTo - etap 2.1 " << endl;
			board[x_][y_] = board[x][y];
			board[x][y] = EMPTY;
			if ((y_ == 7 && player == -1) || (y_ == 0 && player == 1)) {
				cout << "moveTo - etap 2.1.1" << endl;
				board[x_][y_] = (FIELD)(player * 2);
			}
			return true;
		}
		if ((abs(x - x_) == 2) && abs(board[x][y]) == 1) {
			cout << "moveTo - etap 2.2 " << endl;
			board[x_][y_] = board[x][y];
			board[x][y] = EMPTY;
			board[(x + x_) / 2][(y + y_) / 2] = EMPTY;
			if ((y_ == 7 && player == -1) || (y_ == 0 && player == 1)) {
				cout << "moveTo - etap 2.2.1 " << endl;
				board[x_][y_] = (FIELD)(player * 2);
			}
			return true;
		}
		if (abs(board[x][y]) == 2 && (!checkBeatings(player))) {
			cout << "moveTo - etap 2.3.0 " << endl;
			board[x_][y_] = board[x][y];
			if (x < x_) {
				if (y < y_) {
					//++
					cout << "moveTo - etap 2.3 " << endl;
					for (; x < x_ && y < y_; x++, y++) {
						board[x][y] = EMPTY;
					}
					return true;
				}
				else {
					//+-
					cout << "moveTo - etap 2.4 " << endl;
					for (; x < x_ && y > y_; x++, y--) {
						board[x][y] = EMPTY;
					}
					return true;
				}
			}
			else {
				if (y < y_) {
					//-+
					cout << "moveTo - etap 2.5 " << endl;
					for (; x > x_ && y < y_; x--, y++) {
						board[x][y] = EMPTY;
					}
					return true;
				}
				else {
					//--
					cout << "moveTo - etap 2.6 " << endl;
					for (; x > x_ && y > y_; x--, y--) {
						board[x][y] = EMPTY;
					}
					return true;
				}
			}
		}
		if (abs(board[x][y]) == 2 && checkBeatings(player)) {
			cout << "Damka ma bicie " << endl;
			if (x < x_) {
				if (y < y_) {
					//++
					for (int i = x + 1, j = y + 1; i < x_ && j < y_; i++, j++){
						if (board[i][j] != EMPTY){
							board[i][j] = EMPTY;
							board[x_][y_] = board[x][y];
							board[x][y] = EMPTY;
							return true;
						}
					}
					return false;
				}
				else {
					//+-
					for (int i = x + 1, j = y - 1; i < x_ && j > y_; i++, j--){
						if (board[i][j] != EMPTY){
							board[i][j] = EMPTY;
							board[x_][y_] = board[x][y];
							board[x][y] = EMPTY;
							return true;
						}
					}
					return false;
				}
			}
			else {
				if (y < y_) {
					//-+
					for (int i = x - 1, j = y + 1; i > x_ && j < y_; i--, j++){
						if (board[i][j] != EMPTY){
							board[i][j] = EMPTY;
							board[x_][y_] = board[x][y];
							board[x][y] = EMPTY;
							return true;
						}
					}
					return false;
				}
				else {
					//--
					for (int i = x - 1, j = y - 1; i > x_ && j > y_; i--, j--){
						if (board[i][j] != EMPTY){
							board[i][j] = EMPTY;
							board[x_][y_] = board[x][y];
							board[x][y] = EMPTY;
							return true;
						}
					}
					return false;
				}
			}
		}
	}
	cout << "Ruch niemozliwy do wykonania " << endl;
	return false;
}

void Board::promotion(int x, int y)
{
	board[x][y] = FIELD(board[x][y] * 2);
}

void Board::Display() {
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (board[j][i] == -2) cout << "W ";
			if (board[j][i] == -1) cout << "w ";
			if (board[j][i] == 0) cout << "  ";
			if (board[j][i] == 1) cout << "b ";
			if (board[j][i] == 2) cout << "B ";
		}
		cout << i << endl;
	}
}

Board::Board() {
	for (int i = 1; i < 8; i += 2) {
		board[i][5] = BLACK;
		board[i][7] = BLACK;
		board[i][1] = WHITE;
		board[i][6] = EMPTY;
		board[i][4] = EMPTY;
		board[i][2] = EMPTY;
		board[i][0] = EMPTY;
		board[i][3] = EMPTY;
		board[i - 1][6] = BLACK;
		board[i - 1][0] = WHITE;
		board[i - 1][2] = WHITE;
		board[i - 1][7] = EMPTY;
		board[i - 1][5] = EMPTY;
		board[i - 1][3] = EMPTY;
		board[i - 1][1] = EMPTY;
		board[i - 1][4] = EMPTY;
	}
}
Board::~Board() {
}

Board::Board(const Board & board){
	for (size_t i = 0; i < 8; i++){
		for (size_t j = 0; j < 8; j++){			
			this->board[i][j] = board.board[i][j];
		}
	}
}

FIELD Board::getField(int x, int y){
	return board[x][y];
}
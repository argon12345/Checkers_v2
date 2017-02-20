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

vector <Coord> AI::getSolution(int cavity)
{
	reverse();
	cavity = 6;
	clearMovements();
	movements();
	//system("CLS");
	//cout << "getSolution: Mozliwe ruchy oraz tablica" << endl;
	//displayCoord();
	//Board::Display();

	if (_coord.size() == 1) {
		displayCoord();
		Board::Display();
		return _coord[0];
	}

	for (auto & it : _coord) {
		nodeValue.push_back(AI(*this).treeMinMax(it, cavity - 1));
	}
	int best = INT32_MIN;
	int iBest = 0;
	for (size_t i = 0; i < nodeValue.size(); i++) {
		if (best < nodeValue[i]) {
			best = nodeValue[i];
			iBest = i;
		}
	}
	//system("CLS");
	displayCoord();
	Board::Display();

	vector<vector<Coord>> bestResultCoord;
	for (int i = 0; i < nodeValue.size(); i++) {
		if (nodeValue[i] == best) {
			bestResultCoord.push_back(_coord[i]);
		}
	}

	if (bestResultCoord.empty()) {
		return _coord[0];
	}
	else {
		return bestResultCoord[rand() % bestResultCoord.size()];
	}
}
void AI::movements() {
	_coord.clear();
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			movementWithBeatings(i, j, 0, vector <Coord>());
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
void AI::movementWithBeatings(int i, int j, int step = 0, vector <Coord> & tempCoord = vector<Coord>()) {
	//Done 100%
	int counter = 0;
	if (Board::board[i][j] == player) {
		if (player == P_WHITE) {
			if ((i < 6 && j < 6) && (Board::board[i + 2][j + 2] == EMPTY) && (Board::board[i + 1][j + 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i + 2, j + 2, step, tempCoord);

					counter--;
				}
				else {
					counter++;
					//vector <Coord> temp;
					//temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					//_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i + 2, j + 2, step, tempCoord);
					counter--;
				}
			}
			if ((i < 6 && j > 1) && (Board::board[i + 2][j - 2] == EMPTY) && (Board::board[i + 1][j - 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i + 2, j - 2, step, tempCoord);
					counter--;
				}
				else {
					counter++;
					//vector <Coord> temp;
					//temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					//_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i + 2, j - 2, step, tempCoord);
					counter--;
				}
			}
			if ((i > 1 && j < 6) && (Board::board[i - 2][j + 2] == EMPTY) && (Board::board[i - 1][j + 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i - 2, j + 2, step, tempCoord);
					counter--;
				}
				else {
					counter++;
					//vector <Coord> temp;
					//temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					//_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i - 2, j + 2, step, tempCoord);
					counter--;
				}
			}
			if ((i > 1 && j > 1) && (Board::board[i - 2][j - 2] == EMPTY) && (Board::board[i - 1][j - 1] > EMPTY)) {
				if (counter == 0) {
					counter++;
					movementsWithBeatingsFromTo(i, j, i - 2, j - 2, step + 1, tempCoord);
					counter--;
				}
				else {
					counter++;
					//vector <Coord> temp;
					//temp.assign(_coord[_coord.size() - 1].begin(), _coord[_coord.size() - 1].begin() + step);
					//_coord.push_back(temp);
					movementsWithBeatingsFromTo(i, j, i - 2, j - 2, step + 1, tempCoord);
					counter--;
				}
			}
		}
		//else {
		//	if ((i < 6 && j < 6) && (Board::board[i + 2][j + 2] == EMPTY) && (Board::board[i + 1][j + 1] < EMPTY)) {
		//		_coord.push_back(vector<Coord>());
		//		_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j + 2));
		//	}
		//	if ((i < 6 && j > 1) && (Board::board[i + 2][j - 2] == EMPTY) && (Board::board[i + 1][j - 1] < EMPTY)) {
		//		_coord.push_back(vector<Coord>());
		//		_coord[_coord.size() - 1].push_back(Coord(i, j, i + 2, j - 2));
		//	}
		//	if ((i > 1 && j < 6) && (Board::board[i - 2][j + 2] == EMPTY) && (Board::board[i - 1][j + 1] < EMPTY)) {
		//		_coord.push_back(vector<Coord>());
		//		_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j + 2));
		//	}
		//	if ((i > 1 && j > 1) && (Board::board[i - 2][j - 2] == EMPTY) && (Board::board[i - 1][j - 1] < EMPTY)) {
		//		_coord.push_back(vector<Coord>());
		//		_coord[_coord.size() - 1].push_back(Coord(i, j, i - 2, j - 2));
		//	}
		//}
	}
	//TODO
	if (Board::board[i][j] == player * 2) {
		for (int k = 1, l = 1; i + k < 7 && j + l < 7; k++, l++) {

			// Sprawdzanie czy pole jest puste
			if (Board::board[i + k][j + l] == EMPTY) {
				//cout << "Damka: Pole " << i + k << " " << j + l << " jest puste" << endl;
				continue;
			}

			// Sprawdzenie czy na nastepnym polu stoi pionek przeciwnika
			if ((Board::board[i + k][j + l] == player * -1) || (Board::board[i + k][j + l] == player * -2)) {

				//Zapamiêtanie pozycji wroga
				int posEx = i + k;
				int posEy = j + l;

				// Sprawdzenie ile kolejnych pól jest pustych
				for (int m = 1, n = 1; i + k + m < 8 && j + l + n < 8; m++, n++) {
					//cout << " ++ " << endl;
					if (Board::board[i + k + m][j + l + n] == EMPTY) {
						movementsWithBeatingsFromToQueen(i, j, (i + k + m), (j + l + n), posEx, posEy, step, tempCoord);
					}
					else {
						break;
					}

				}
				break;

			}
		}
		for (int k = 1, l = 1; i - k > 0 && j + l < 7; k++, l++) {

			// Sprawdzanie czy pole jest puste
			if (Board::board[i - k][j + l] == EMPTY) {
				//cout << "Damka: Pole " << i - k << " " << j + l << " jest puste" << endl;
				continue;
			}

			// Sprawdzenie czy na nastepnym polu stoi pionek przeciwnika
			if ((Board::board[i - k][j + l] == player * -1) || (Board::board[i - k][j + l] == player * -2)) {

				//Zapamiêtanie pozycji wroga
				int posEx = i - k;
				int posEy = j + l;

				// Sprawdzenie ile kolejnych pól jest pustych
				for (int m = 1, n = 1; i - k - m >= 0 && j + l + n < 8; m++, n++) {
					//cout << " -+ " << endl;
					if (Board::board[i - k - m][j + l + n] == EMPTY) {
						movementsWithBeatingsFromToQueen(i, j, (i - k - m), (j + l + n), posEx, posEy, step, tempCoord);
					}
					else {
						break;
					}
				}
				break;
			}
		}
		for (int k = 1, l = 1; i + k < 7 && j - l > 0; k++, l++) {

			// Sprawdzanie czy pole jest puste
			if (Board::board[i + k][j - l] == EMPTY) {
				//cout << "Damka: Pole " << i + k << " " << j - l << " jest puste" << endl;
				continue;
			}

			// Sprawdzenie czy na nastepnym polu stoi pionek przeciwnika
			if ((Board::board[i + k][j - l] == player * -1) || (Board::board[i + k][j - l] == player * -2)) {

				//Zapamiêtanie pozycji wroga
				int posEx = i + k;
				int posEy = j - l;

				// Sprawdzenie ile kolejnych pól jest pustych
				for (int m = 1, n = 1; i + k + m < 8 && j - l - n >= 0; m++, n++) {
					//cout << " ++ " << endl;
					if (Board::board[i + k + m][j - l - n] == EMPTY) {
						movementsWithBeatingsFromToQueen(i, j, (i + k + m), (j - l - n), posEx, posEy, step, tempCoord);
					}
					else {
						break;
					}

				}
				break;
			}
		}
		for (int k = 1, l = 1; i - k > 0 && j - l > 0; k++, l++) {

			// Sprawdzanie czy pole jest puste
			if (Board::board[i - k][j - l] == EMPTY) {
				//cout << "Damka: Pole " << i - k << " " << j - l << " jest puste" << endl;
				continue;
			}

			// Sprawdzenie czy na nastepnym polu stoi pionek przeciwnika
			if ((Board::board[i - k][j - l] == player * -1) || (Board::board[i - k][j - l] == player * -2)) {

				//Zapamiêtanie pozycji wroga
				int posEx = i - k;
				int posEy = j - l;

				// Sprawdzenie ile kolejnych pól jest pustych
				for (int m = 1, n = 1; i - k - m >= 0 && j - l - n >= 0; m++, n++) {
					//cout << " -- " << endl;
					if (Board::board[i - k - m][j - l - n] == EMPTY) {
						movementsWithBeatingsFromToQueen(i, j, (i - k - m), (j - l - n), posEx, posEy, step, tempCoord);
					}
					else {
						break;
					}
				}
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
		for (int k = 1, l = 1; ((k + i) < 8) && ((l + j) < 8); k++, l++) {
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
		for (int k = 1, l = 1; i - k >= 0 && l + j < 8; k++, l++) {
			if (board[i - k][j + l] == EMPTY) {
				_coord.push_back(vector<Coord>());
				_coord[_coord.size() - 1].push_back(Coord(i, j, i - k, j + l));
			}
			else {
				break;
			}

		}
		for (int k = 1, l = 1; i - k >= 0 && j - l >= 0; k++, l++) {
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
	nodeValue.clear();
}
void AI::rating(PLAYER player) {
	int white = 0,			// Zliczanie bia³ych pionków
		white_K = 0,		// Zliczanie bia³ych królowych 
		black = 0,			// Zliczanie czarnych pionków
		black_K = 0,		// Zliczanie czarnych królowych
		zone_I_w = 0,		// Premia za pionki w odpowiedniej strefie
		zone_II_w = 0,
		zone_I_b = 0,
		zone_II_b = 0,
		up_W = 0,
		up_B = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Board::board[i][j] == EMPTY) {
				continue;
			}
			else {
				if (Board::board[i][j] == player) {
					white++;
					up_W += j ;
					if (i < 7 && i > 0 && j > 0 && j < 7) {
						zone_I_w++;
					}
					if (i < 6 && i > 1 && j > 1 && j < 6) {
						zone_II_w++;
					}
				}
				else if (Board::board[i][j] == player * 2) {
					white_K++;
				}
				else if (Board::board[i][j] == player * -1) {
					black++;
					up_B += 7 - j;
					if (i < 7 && i > 0 && j > 0 && j < 7) {
						zone_I_b++;
					}
					if (i < 6 && i > 1 && j > 1 && j < 6) {
						zone_II_b++;
					}
				}
				else if (Board::board[i][j] == player * -2) {
					black_K++;
				}
			}
		}
	}

	int result_W = 0, result_B = 0;
	white_K *= 50;
	black_K *= 50;
	white *= 12;
	black *= 12;
	zone_I_w *= 2;
	zone_II_w *= 3;
	zone_I_b *= 2;
	zone_II_b *= 2;

	value = white + white_K + zone_I_w + zone_II_w - black - black_K - zone_I_b - zone_II_b + up_W - up_B;


}
int AI::getValue() {
	return value;
}
void AI::displayCoord() {
	for (size_t i = 0; i < _coord.size(); i++) {
		if (i < nodeValue.size()) {
			cout << nodeValue[i] << " : ";
		}
		for (size_t j = 0; j < _coord[i].size(); j++) {
			cout << _coord[i][j].x << "," << _coord[i][j].y << " do " << _coord[i][j].x_ << "," << _coord[i][j].y_ << " || ";
		}
		cout << endl;
	}
}
inline void AI::movementsWithBeatingsFromTo(int i, int j, int x, int y, int step, vector <Coord> tempCoord) {
	if (step == 0) {

		// Tworzenie nowego wêz³a
		vector<Coord> temp2;
		temp2.push_back(Coord(i, j, x, y));
		_coord.push_back(temp2);

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[(i + x) / 2][(j + y) / 2];
		Board::board[(i + x) / 2][(j + y) / 2] = EMPTY;
		Board::board[i][j] = EMPTY;

		if ((y == 7 && board[x][y] == P_WHITE) || (y == 0 && board[x][y] == P_BLACK)) {

			promotion(x, y);
			if (Board::checkBeating(x, y)) {
				tempCoord = _coord.back();
				_coord.pop_back();
				movementWithBeatings(x, y, step + 1, tempCoord);
			}
			unPromotion(x, y);
		}
		else {
			// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
			movementWithBeatings(x, y, step + 1, tempCoord);
		}

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[(i + x) / 2][(j + y) / 2] = temp;

	}
	else {
		if (!_coord.empty()) {
			_coord[_coord.size() - 1].push_back(Coord(i, j, x, y));
		}
		else {
			// Tworzenie nowego wêz³a
			vector<Coord> temp2;
			temp2.push_back(Coord(i, j, x, y));
			_coord.push_back(temp2);
		}

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[(i + x) / 2][(j + y) / 2];
		Board::board[(i + x) / 2][(j + y) / 2] = EMPTY;
		Board::board[i][j] = EMPTY;

		if ((y == 7 && board[x][y] == P_WHITE) || (y == 0 && board[x][y] == P_BLACK)) {

			promotion(x, y);
			if (Board::checkBeating(x, y)) {
				tempCoord = _coord.back();
				_coord.pop_back();
				movementWithBeatings(x, y, step + 1, tempCoord);
			}
			unPromotion(x, y);
		}
		else {
			// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
			movementWithBeatings(x, y, step + 1, tempCoord);
		}

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[(i + x) / 2][(j + y) / 2] = temp;
	}
}
inline void AI::movementsWithBeatingsFromToQueen(int i, int j, int x, int y, int m, int n, int step, vector <Coord>  tempCoord) {
	if (step == 0) {

		// Tworzenie nowego wêz³a
		//vector<Coord> temp2;
		//temp2.push_back(Coord(i, j, x, y));
		//_coord.push_back(temp2);

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[m][n];
		Board::board[m][n] = EMPTY;
		Board::board[i][j] = EMPTY;

		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		// Jeœli nie, tworzenie nowego wêz³a.
		tempCoord.push_back(Coord(i, j, x, y));
		if (Board::checkBeating(x, y)) {
			//cout << "STEP " << step << " Damka ma kolejne bicie" << endl;
			movementWithBeatings(x, y, step + 1, tempCoord);
		}
		else {
			//cout << "STEP " << step << " Damka nie ma juz bicia" << endl;
			vector<Coord> temp(tempCoord);
			_coord.push_back(temp);
		}

		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[m][n] = temp;

	}
	else {
		//_coord[_coord.size() - 1].push_back(Coord(i, j, x, y));

		//Przemieszczanie pionka
		Board::board[x][y] = Board::board[i][j];
		FIELD temp = Board::board[m][n];
		Board::board[m][n] = EMPTY;
		Board::board[i][j] = EMPTY;

		// Rekurencyjnie sprawdzanie czy posiada jeszcze jakieœ bicia.
		tempCoord.push_back(Coord(i, j, x, y));
		if (Board::checkBeating(x, y)) {
			movementWithBeatings(x, y, step + 1, tempCoord);
		}
		else {
			vector<Coord> temp(tempCoord);
			_coord.push_back(temp);
		}
		//Powrót pionka na w³aœciwe miejsce
		Board::board[i][j] = Board::board[x][y];
		Board::board[x][y] = EMPTY;
		Board::board[m][n] = temp;

	}
}

int AI::treeMinMax(vector<Coord>actCoord, int cavity) {

	for (auto & it : actCoord) {
		if (!moveTo(it.x, it.y, it.x_, it.y_)) {
			//cout << "MoveTo: error " << endl;
			//displayCoord();
			//Board::Display();
			//cout << endl << endl;
		}
	}
	clearMovements();
	reverse();
	movements();
	if (cavity > 0) {
		nodeValue.clear();
		for (auto &it : _coord) {
			//AI::Board::Display();
			nodeValue.push_back(AI(*this).treeMinMax(it, cavity - 1));
		}

		int best = 0;

		if (cavity % 2 == 1) {
			best = INT_MIN;
			for (auto &it : nodeValue) {
				if (best < it) {
					best = it;
				}
			}
			if (best == INT_MIN) {
				best *= -1;
			}
			else {
				return best;
			}
		}
		else {
			best = INT_MAX;
			for (auto &it : nodeValue) {
				if (best > it) {
					best = it;
				}
			}
			if (best == INT_MAX) {
				best *= -1;
			}
			else {
				return best;
			}
		}


		//for			(auto &it : nodeValue) {
		//	//cout << "ruch: " << it << endl;
		//}

		//cout << "Best : " << best << endl;;
		
	}
	else {
		rating(P_WHITE);
		//cout << "Rating : " << value << endl;
		return value;
	}



}

#include <iostream>
#include "graphic.h"

using namespace std;

void unitTest(){
	Board game;
	game.Display();
	cout << "001 Wynik: " << (game.checkMoveTo(6, 2, 7, 3) ? true : false) << endl;
	cout << "002 Wynik: " << (game.checkMoveTo(4, 2, 7, 3) ? false : true) << endl;
	cout << "003 Wynik: " << (game.checkMoveTo(1, 5, 0, 4) ? true : false) << endl;
	cout << "004 Wynik: " << (game.checkBeatings(P_WHITE) ? false : true) << endl;
	cout << "005 Wynik: " << (game.checkBeatings(P_BLACK) ? false : true) << endl;
	cout << "006 Wynik: " << (game.moveTo(6, 2, 7, 3) ? true : false) << endl;
	cout << "007 Wynik: " << (game.moveTo(1, 5, 0, 4) ? true : false) << endl;
	cout << "008 Wynik: " << (game.moveTo(4, 2, 7, 3) ? false : true) << endl;
	cout << "009 Wynik: " << (game.moveTo(7, 3, 6, 4) ? true : false) << endl;
	cout << "010 Wynik: " << (game.moveTo(3, 5, 2, 4) ? false : true) << endl;
	cout << "011 Wynik: " << (game.moveTo(5, 5, 7, 3) ? true : false) << endl;
	cout << "012 Wynik: " << (game.moveTo(5, 1, 3, 3) ? false : true) << endl;
	cout << "013 Wynik: " << (game.moveTo(7, 5, 6, 4) ? true : false) << endl;
	game.promotion(4, 2);
	cout << "014 Wynik: " << (game.moveTo(4, 2, 7, 5) ? true : false) << endl;
	cout << "015 Wynik: " << (game.moveTo(2, 2, 1, 3) ? true : false) << endl;
	game.promotion(0, 4);
	cout << "016 Wynik: " << (game.moveTo(0, 4, 2, 2) ? true : false) << endl;






	game.Display();


}
int main(int argc, char* argv){
	//unitTest();
	AI ai = AI(Board());
	time_t timeStart = clock();
	ai.movements();
	Sleep(100);
	time_t timeStop = clock();
	ai.displayCoord();
	cout << "Uplynelo: " << difftime(timeStop, timeStart);
	Graphic graphic = Graphic();
	graphic.run();
	    
	system("PAUSE");

	//return 0;
}
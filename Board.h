#ifndef BOARD_H
#define BOARD_H

#include <windows.h>
#include <iostream>
#include "Snake.h"
#include <conio.h>

using namespace std;

class Board {

private:
	HANDLE qwerty;

	int Tablica[80][25];
	Snake snake;
	int jabx, jaby;

	void jablko(int & jabx, int & jaby, int Tablica[80][25]);
	void gotoxy(int x, int y);
public:
	Board();
	void writeTitle();
	void writeAutor();
	void drawFrame();
	void clean();
	void prepare();
	void nextMove();

	void showMenu();
	void hideMenu();

	void snakeInput(char input);

	bool zjadl;
	bool koniec;
	int licznik;
};


#endif
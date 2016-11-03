#ifndef BOARD_H
#define BOARD_H

#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Snake.h"
#include "Constans.h"

using namespace std;

class Board {

private:

	HANDLE handle;
	Dir Tab[80][25];
	Snake snake;

	bool gameOver;
	bool eatenApple;
	int points;

	void newApple(int &, int &);
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
	bool isGameOver();	
	void gotoxy(int x, int y);
};


#endif
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "Board.h"
#include "Snake.h"
using namespace std;

void gotoxy(int x, int y)
{
	COORD cord;

	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);

}



/*void Autor()
{
	gotoxy(60, 39);
	cout << "by MACIEJ RUSZCZYK";
}*/


int main()      //*************************************************************
{

	srand(time(NULL));
	Board board;

	//HANDLE qwerty = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(qwerty, FOREGROUND_BLUE | FOREGROUND_GREEN);

	board.drawFrame();
	

	//SetConsoleTextAttribute(qwerty, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	board.writeTitle();
	
	char input;

	do
	{
		board.prepare();
		board.clean();

		board.licznik = 0;
		board.zjadl = true;
		board.koniec = false;
	
		board.writeAutor();

		
		

		board.showMenu();


		do
		{
			input = _getch();
		} while (input != 32 && input != 27);
		if (input == 27) break;

		board.hideMenu();

		gotoxy(31, 22);  cout << "*****";

		do
		{
			do
			{
				board.nextMove();	

			} while (!_kbhit() && !board.koniec);

			if (board.koniec == true) break;

			input = _getch();
			board.snakeInput(input);

		} while (input != 27 && board.koniec == false);

		gotoxy(33, 39);
		cout << "Nacisnij SPACJE";

		do
		{
			input = _getch();
		} while (input != 32);

		gotoxy(33, 39);
		cout << "                    ";

	} while (input != 27);



	gotoxy(0, 36);

	return 0;
}

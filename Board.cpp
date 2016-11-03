#include "Board.h"

Board::Board() {
	qwerty = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Board::gotoxy(int x, int y)
{
	COORD cord;

	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);

}

void Board::writeTitle(){
	SetConsoleTextAttribute(qwerty, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


	char Tab[7][34] =
	{
		{ '*','*','*','*',' ','*',' ',' ','*',' ' ,' ' ,'*' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,'*' ,'*' },
		{ '*',' ',' ',' ',' ','*','*',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*',' ',' ',' ',' ','*','*',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*','*','*','*',' ','*',' ','*','*',' ' ,'*' ,'*' ,'*' ,'*' ,' ' ,'*' ,'*' ,' ' ,' ' ,' ' ,'*' ,'*' ,'*' ,' ' },
		{ ' ',' ',' ','*',' ','*',' ','*','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,' ' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ ' ',' ',' ','*',' ','*',' ',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*','*','*','*',' ','*',' ',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,'*' ,'*' },
	};

	for (int i = 0; i<7; ++i)
	{
		gotoxy(28, 2 + i);
		cout << Tab[i] << endl;
	}

	
}

void Board::clean()
{
	gotoxy(0, 0);
	cout << "    ";

	for (int j = 13; j<36; j++)
		for (int i = 1; i<79; i++)
		{
			gotoxy(i, j);
			cout << " ";
		}

	for (int j = 0; j<25; ++j)
		for (int i = 0; i<80; ++i)
			Tablica[i][j] = 0;

	

	for (int i = 0; i<80; ++i)
	{
		Tablica[i][0] = -1;
		Tablica[i][24] = -1;
	}
	for (int i = 0; i<25; ++i)
	{
		Tablica[0][i] = -1;
		Tablica[79][i] = -1;
	}
	
	Tablica[snake.getHeadX()][snake.getHeadY() - 12] = 2;
	Tablica[snake.getHeadX() - 1][snake.getHeadY() - 12] = 2;
	Tablica[snake.getHeadX() - 2][snake.getHeadY() - 12] = 2;
	Tablica[snake.getHeadX() - 3][snake.getHeadY() - 12] = 2;
	Tablica[snake.getHeadX() - 4][snake.getHeadY() - 12] = 2;
	
}

void Board::prepare() {
	snake.setHeadDir(2);
	snake.setHeadX(35);
	snake.setHeadY(22);
	snake.setTailX(31);
	snake.setTailY(22);
}

void Board::jablko(int & jabx, int & jaby, int Tablica[80][25])
{
	do
	{
		jabx = rand() % 78 + 1;
		jaby = rand() % 23 + 1;
	} while (Tablica[jabx][jaby] != 0);

	Tablica[jabx][jaby] = 5;
	jaby += 12;
}

void Board::nextMove() {
	SetConsoleTextAttribute(qwerty, FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (zjadl == true)
	{
		jablko(jabx, jaby, Tablica);
		gotoxy(jabx, jaby); cout << "*";
	}


	SetConsoleTextAttribute(qwerty, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Tablica[snake.getHeadX()][snake.getHeadY() - 12] = snake.getHeadDir();

	gotoxy(snake.getTailX(), snake.getTailY());
	//snake.zwrot = Tablica[snake.getTailX()][snake.getTailY() - 12];
	snake.setTailDir(Tablica[snake.getTailX()][snake.getTailY() - 12]);

	if (zjadl == false)
	{
		cout << " ";
		//snake.zwrot = Tablica[snake.getTailX()][snake.getTailY() - 12];
		snake.setTailDir(Tablica[snake.getTailX()][snake.getTailY() - 12]);
		Tablica[snake.getTailX()][snake.getTailY() - 12] = 0;

		if (snake.getTailDir() == 1) //--snake.ogony;
			snake.decTailY();
		else if (snake.getTailDir() == 2) //++snake.ogonx;
			snake.incTailX();
		else if (snake.getTailDir() == 3) //++snake.ogony;
			snake.incTailY();
		else if (snake.getTailDir() == 4) //--snake.ogonx;
			snake.decTailX();

		gotoxy(snake.getTailX(), snake.getTailY()); cout << '*';
	}
	zjadl = false;

	gotoxy(snake.getHeadX(), snake.getHeadY());

	if (snake.getHeadDir() == 1) //--snake.y;
		snake.decHeadY();
	else if (snake.getHeadDir() == 2) //++snake.x;
		snake.incHeadX();
	else if (snake.getHeadDir() == 3) //++snake.y;
		snake.incHeadY();
	else if (snake.getHeadDir() == 4) //--snake.x;
		snake.decHeadX();

	gotoxy(snake.getHeadX(), snake.getHeadY());


	if (Tablica[snake.getHeadX()][snake.getHeadY() - 12] != 0 && Tablica[snake.getHeadX()][snake.getHeadY() - 12] != 5)
	{
		koniec = true;
		//break;
		return;
	}
	if (Tablica[snake.getHeadX()][snake.getHeadY() - 12] == 5)
	{
		zjadl = true;
		++licznik;
	}
	gotoxy(snake.getHeadX(), snake.getHeadY());
	cout << '*';



	gotoxy(0, 0);
	cout << licznik;

	if (licznik<80)
		Sleep(80 - licznik);
	else Sleep(1);
}

void Board::showMenu() {
	gotoxy(33, 20);
	cout << "SPACJA - START";
	gotoxy(33, 21);
	cout << " ESC   - WYJSCIE";
}

void Board::hideMenu() {
	for (int j = 20; j<22; ++j)
			for (int i = 33; i<50; ++i){
				gotoxy(i, j); cout << " ";
			}
}

void Board::drawFrame() {
	SetConsoleTextAttribute(qwerty, FOREGROUND_BLUE | FOREGROUND_GREEN);

	int x1 = 0;
	int y1 = 12;
	int x2 = 79;
	int y2 = 36;

	for (int i = x1 + 1; i<x2; ++i)
	{
		gotoxy(i, y1);
		cout << char(205);
		gotoxy(i, y2);
		cout << char(205);
	}

	for (int i = y1 + 1; i<y2; ++i)
	{
		gotoxy(x1, i);
		cout << char(186);
		gotoxy(x2, i);
		cout << char(186);
	}
	gotoxy(x1, y1); cout << char(201);
	gotoxy(x2, y1); cout << char(187);
	gotoxy(x1, y2); cout << char(200);
	gotoxy(x2, y2); cout << char(188);
}

void Board::snakeInput(char input) {
	
	int kierunek = snake.getHeadDir();

		switch (input)
		{
		case 'w': if (kierunek == 2 || kierunek == 4) snake.setHeadDir(1); break;
		case 's': if (kierunek == 2 || kierunek == 4) snake.setHeadDir(3); break;
		case 'd': if (kierunek == 1 || kierunek == 3) snake.setHeadDir(2); break;
		case 'a': if (kierunek == 1 || kierunek == 3) snake.setHeadDir(4); break;
		}
	
}
void Board::writeAutor() {
	SetConsoleTextAttribute(qwerty, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(60, 39);
	cout << "by MACIEJ RUSZCZYK";
}
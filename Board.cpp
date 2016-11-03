#include "Board.h"

Board::Board() {
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Board::gotoxy(int x, int y)
{
	COORD cord;

	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);

}

void Board::writeTitle(){
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


	char Tab[7][34] ={
		{ '*','*','*','*',' ','*',' ',' ','*',' ' ,' ' ,'*' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,'*' ,'*' },
		{ '*',' ',' ',' ',' ','*','*',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*',' ',' ',' ',' ','*','*',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*','*','*','*',' ','*',' ','*','*',' ' ,'*' ,'*' ,'*' ,'*' ,' ' ,'*' ,'*' ,' ' ,' ' ,' ' ,'*' ,'*' ,'*' ,' ' },
		{ ' ',' ',' ','*',' ','*',' ','*','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,' ' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ ' ',' ',' ','*',' ','*',' ',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,' ' ,' ' },
		{ '*','*','*','*',' ','*',' ',' ','*',' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,' ' ,' ' ,'*' ,' ' ,'*' ,'*' ,'*' ,'*' },
	};

	for (int i = 0; i<7; ++i){
		gotoxy(28, 2 + i);
		cout << Tab[i] << endl;
	}

	
}

void Board::clean()
{
	gotoxy(0, 0);
	cout << "    ";

	for (int j = 13; j<36; j++)
		for (int i = 1; i<79; i++){
			gotoxy(i, j);
			cout << " ";
		}

	for (int j = 0; j<25; ++j)
		for (int i = 0; i<80; ++i)
			Tab[i][j] = Dir::NONE;

	

	for (int i = 0; i<80; ++i){
		Tab[i][0] = Dir::CRASH;
		Tab[i][24] = Dir::CRASH;
	}
	for (int i = 0; i<25; ++i){
		Tab[0][i] = Dir::CRASH;
		Tab[79][i] = Dir::CRASH;
	}
	
	Tab[snake.getHeadX()][snake.getHeadY() - 12] = Dir::RIGHT;
	Tab[snake.getHeadX() - 1][snake.getHeadY() - 12] = Dir::RIGHT;
	Tab[snake.getHeadX() - 2][snake.getHeadY() - 12] = Dir::RIGHT;
	Tab[snake.getHeadX() - 3][snake.getHeadY() - 12] = Dir::RIGHT;
	Tab[snake.getHeadX() - 4][snake.getHeadY() - 12] = Dir::RIGHT;
	
}

void Board::prepare() {
	snake.setHeadDir(Dir::RIGHT);
	snake.setHeadX(35);
	snake.setHeadY(22);
	snake.setTailX(31);
	snake.setTailY(22);

	points = 0;
	eatenApple = true;
	gameOver = false;
}

void Board::newApple(int &x, int &y)
{
	do{
		x = rand() % 78 + 1;
		y = rand() % 23 + 1;
	} while (Tab[x][y] != 0);

	Tab[x][y] = Dir::APPLE;
	y += 12;
}

void Board::nextMove() {
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (eatenApple == true){
	
		int x, y;
		newApple(x, y);
		gotoxy(x, y); cout << "*";
	}


	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	Tab[snake.getHeadX()][snake.getHeadY() - 12] = snake.getHeadDir();

	gotoxy(snake.getTailX(), snake.getTailY());
	snake.setTailDir(Tab[snake.getTailX()][snake.getTailY() - 12]);

	if (eatenApple == false){

		cout << " ";
		snake.setTailDir(Tab[snake.getTailX()][snake.getTailY() - 12]);
		Tab[snake.getTailX()][snake.getTailY() - 12] = Dir::NONE;

		if (snake.getTailDir() == Dir::UP) 
			snake.decTailY();
		else if (snake.getTailDir() == Dir::RIGHT) 
			snake.incTailX();
		else if (snake.getTailDir() == Dir::DOWN) 
			snake.incTailY();
		else if (snake.getTailDir() == Dir::LEFT) 
			snake.decTailX();

		gotoxy(snake.getTailX(), snake.getTailY()); cout << '*';
	}
	eatenApple = false;

	gotoxy(snake.getHeadX(), snake.getHeadY());

	if (snake.getHeadDir() == Dir::UP) //--snake.y;
		snake.decHeadY();
	else if (snake.getHeadDir() == Dir::RIGHT) //++snake.x;
		snake.incHeadX();
	else if (snake.getHeadDir() == Dir::DOWN) //++snake.y;
		snake.incHeadY();
	else if (snake.getHeadDir() == Dir::LEFT) //--snake.x;
		snake.decHeadX();

	gotoxy(snake.getHeadX(), snake.getHeadY());


	if (Tab[snake.getHeadX()][snake.getHeadY() - 12] != Dir::NONE && Tab[snake.getHeadX()][snake.getHeadY() - 12] != Dir::APPLE){

		gameOver = true;
		//break;
		return;
	}
	if (Tab[snake.getHeadX()][snake.getHeadY() - 12] == Dir::APPLE){
	
		eatenApple = true;
		++points;
	}
	gotoxy(snake.getHeadX(), snake.getHeadY());
	cout << '*';



	gotoxy(0, 0);
	cout << points;

	if (points<80)
		Sleep(80 - points);
	else Sleep(1);
}

void Board::showMenu() {
	gotoxy(33, 20);
	cout << "SPACE - PLAY";
	gotoxy(33, 21);
	cout << " ESC  - EXIT";
}

void Board::hideMenu() {
	for (int j = 20; j<22; ++j)
			for (int i = 33; i<50; ++i){
				gotoxy(i, j); cout << " ";
			}
}

void Board::drawFrame() {
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN);

	int x1 = 0;
	int y1 = 12;
	int x2 = 79;
	int y2 = 36;

	for (int i = x1 + 1; i<x2; ++i){
	
		gotoxy(i, y1);
		cout << char(205);
		gotoxy(i, y2);
		cout << char(205);
	}

	for (int i = y1 + 1; i<y2; ++i){
	
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
	
	Dir kierunek = snake.getHeadDir();

		switch (input){
			case 'w': if (kierunek == Dir::RIGHT || kierunek == Dir::LEFT) snake.setHeadDir(Dir::UP); break;
			case 's': if (kierunek == Dir::RIGHT || kierunek == Dir::LEFT) snake.setHeadDir(Dir::DOWN); break;
			case 'd': if (kierunek == Dir::UP || kierunek == Dir::DOWN) snake.setHeadDir(Dir::RIGHT); break;
			case 'a': if (kierunek == Dir::UP || kierunek == Dir::DOWN) snake.setHeadDir(Dir::LEFT); break;
		}
	
}
void Board::writeAutor() {
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	gotoxy(60, 39);
	cout << "by MACIEJ RUSZCZYK";
}

bool Board::isGameOver() {
	return gameOver;
}
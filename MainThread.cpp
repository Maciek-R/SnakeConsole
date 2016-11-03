#include "MainThread.h"

MainThread::MainThread() {

}

void MainThread::startMainLoop() {
	board.drawFrame();
	board.writeTitle();

	char input;

	do {
		board.prepare();
		board.clean();

		board.writeAutor();
		board.showMenu();

		do {
			input = _getch();
		} while (input != 32 && input != 27);
		if (input == 27) break;

		board.hideMenu();

		board.gotoxy(31, 22);  cout << "*****";

		do {
			do {
				board.nextMove();

			} while (!_kbhit() && !board.isGameOver());

			if (board.isGameOver()) break;

			input = _getch();
			board.snakeInput(input);

		} while (input != 27 && !board.isGameOver());

		board.gotoxy(33, 39);
		cout << "Press SPACE";

		do {
			input = _getch();
		} while (input != 32);

		board.gotoxy(33, 39);
		cout << "                    ";

	} while (input != 27);



	board.gotoxy(0, 36);
}
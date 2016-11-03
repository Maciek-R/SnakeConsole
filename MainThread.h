#ifndef MAINTHREAD_H
#define MAINTHREAD_H

#include "Board.h"

class MainThread {
private:
	Board board;

public:
	MainThread();

	void startMainLoop();
};

#endif
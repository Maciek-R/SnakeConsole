#ifndef SNAKE_H
#define SNAKE_H

#include "Constans.h"

class Snake {
public:
private:
	Dir headDir;
	Dir tailDir;
	int headX, headY;
	int tailX, tailY;
	
public:
	Snake();

	Dir getHeadDir();
	int getHeadX();
	int getHeadY();
	int getTailX();
	int getTailY();
	Dir getTailDir();

	void setHeadDir(Dir);
	void setTailDir(Dir);
	void setHeadX(int);
	void setHeadY(int);
	void setTailX(int);
	void setTailY(int);

	void incHeadX();
	void decHeadX();
	void incTailX();
	void decTailX();
	void incHeadY();
	void decHeadY();
	void incTailY();
	void decTailY();

};

#endif
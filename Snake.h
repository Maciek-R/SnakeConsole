#ifndef SNAKE_H
#define SNAKE_H

class Snake {
private:
	int headDir;
	int tailDir;
	int headX, headY;
	int tailX, tailY;
	
public:
	Snake();

	int getHeadDir();
	int getHeadX();
	int getHeadY();
	int getTailX();
	int getTailY();
	int getTailDir();

	void setHeadDir(int);
	void setTailDir(int);
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
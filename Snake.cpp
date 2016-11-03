#include "Snake.h"

Snake::Snake() {
	headDir = 2;
	headX = 35;
	headY = 22;
	tailX = 31;
	tailY = 22;
}

void Snake::setHeadDir(int dir) {
	headDir = dir;
}
void Snake::setTailDir(int dir) {
	tailDir = dir;
}
void Snake::setHeadX(int x) {
	headX = x;
}
void Snake::setHeadY(int y) {
	headY = y;
}
void Snake::setTailX(int x) {
	tailX = x;
}
void Snake::setTailY(int y) {
	tailY = y;
}


void Snake::incHeadX() {
	headX++;
}
void Snake::decHeadX() {
	headX--;
}
void Snake::incTailX() {
	tailX++;
}
void Snake::decTailX() {
	tailX--;
}
void Snake::incHeadY() {
	headY++;
}
void Snake::decHeadY() {
	headY--;
}
void Snake::incTailY() {
	tailY++;
}
void Snake::decTailY() {
	tailY--;
}


int Snake::getHeadDir() {
	return headDir;
}
int Snake::getHeadX() {
	return headX;
}
int Snake::getHeadY() {
	return headY;
}
int Snake::getTailX() {
	return tailX;
}
int Snake::getTailY() {
	return tailY;
}
int Snake::getTailDir() {
	return tailDir;
}

#include <time.h>
#include "MainThread.h"

int main(){   

	srand(time(NULL));

	MainThread MainThread;
	MainThread.startMainLoop();

	return 0;
}

#include <iostream>
//#include <sqlite.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define WINDOW_W 1920*0.75
#define WINDOW_H 1080*0.75

#define BLOCK_W 150
#define BLOCK_H 80
#define BLOCK_DAY 7
#define BLOCK_CLASS 5+5+3

void WindowMain(void)
{
	setfillcolor(DARKGRAY);
	solidrectangle(0, 0, WINDOW_W, WINDOW_H);
	int BlockL = 50;
	int BlockU = 100;
	int iterator_i = 0;
	int iterator_j = 0;
	for (iterator_i = 0; iterator_i < BLOCK_DAY; ++iterator_i)
	{
		for (iterator_j = 0; iterator_j < BLOCK_CLASS; ++iterator_j)
		{
			rectangle(iterator_i*BLOCK_W, iterator_j*BLOCK_H, (iterator_i + 1)*BLOCK_W, (iterator_j + 1)*BLOCK_H);
		}
	}
}

int main()
{
    //std::cout << "Hello World!\n";
	initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	WindowMain();
	system("PAUSE");
	return 0;
}
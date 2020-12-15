#include <iostream>
//#include <sqlite.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define WINDOW_W 1500
#define WINDOW_H 780

#define BLOCK_W 175
#define BLOCK_H 55

#define NUM_DAY 7
#define NUM_CLASS 5+5+3

void WindowMain(void)
{
	//----INIT----

	//DEFINE PLAYGROUND
	setfillcolor(BLACK);
	solidrectangle(0, 0, WINDOW_W, WINDOW_H);
	//DEFINE TABLEAREA
	setfillcolor(DARKGRAY);
	solidrectangle(0, 0, 1295, 780);
	//DEFINE CONTROLAREA
	setfillcolor(LIGHTGRAY);
	solidrectangle(1296, 0, 1500, 780);

	int TABLE_EDGE_X = 30;
	int TABLE_EDGE_Y = 30;

	int iterator_i = 0;
	int iterator_j = 0;

	//DIVISION LINE
	rectangle(TABLE_EDGE_X * 2 + BLOCK_W * 7 + 10, 30, TABLE_EDGE_X * 2 + BLOCK_W * 7 + 10 + 1, WINDOW_H - 30);

	//----TABLEAREA----

	for (iterator_i = 0; iterator_i < NUM_DAY; ++iterator_i)
	{
		for (iterator_j = 0; iterator_j < NUM_CLASS; ++iterator_j)
		{
			rectangle(TABLE_EDGE_X + iterator_i * BLOCK_W, TABLE_EDGE_Y + iterator_j * BLOCK_H, TABLE_EDGE_X + (iterator_i + 1)*BLOCK_W, TABLE_EDGE_Y + (iterator_j + 1)*BLOCK_H);
		}
	}
	
}

int main()
{
	initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	WindowMain();
	system("PAUSE");
	return 0;
}
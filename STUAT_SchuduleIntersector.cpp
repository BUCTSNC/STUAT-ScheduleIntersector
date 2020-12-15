#include <iostream>
//#include <sqlite.h>
#include <graphics.h>
#include <conio.h>
using namespace std;

#define WINDOW_W 1500
#define WINDOW_H 780

#define BLOCK_W 175
#define BLOCK_H 55

#define NUM_DAY_WORKDAY 5
#define NUM_DAY_WEEKEND 2

#define NUM_CLASS_MORN 5
#define NUM_CLASS_NOON 5
#define NUM_CLASS_DUSK 3

#define NUM_DAY (NUM_DAY_WORKDAY+NUM_DAY_WEEKEND)
#define NUM_CLASS (NUM_CLASS_MORN+NUM_CLASS_NOON+NUM_CLASS_DUSK)

void WindowMain(void)
{
	//----INIT----

	//DEFINE PLAYGROUND
	setfillcolor(BLACK);
	solidrectangle(0, 0, WINDOW_W, WINDOW_H);
	//DEFINE TABLEAREA
	setfillcolor(DARKGRAY);
	int TABLEAREA_L = 0;
	int TABLEAREA_U = 0;
	int TABLEAREA_R = 1295;
	int TABLEAREA_D = WINDOW_H;
	solidrectangle(TABLEAREA_L, TABLEAREA_U, TABLEAREA_R, TABLEAREA_D);
	//DEFINE CONTROLAREA
	setfillcolor(LIGHTGRAY);
	int CONTROLAREA_L = 1296;
	int CONTROLAREA_U = 0;
	int CONTROLAREA_R = WINDOW_W;
	int CONTROLAREA_D = WINDOW_H;
	solidrectangle(CONTROLAREA_L, CONTROLAREA_U, CONTROLAREA_R, CONTROLAREA_D);

	int TABLE_EDGE_X = 30;
	int TABLE_EDGE_Y = 30;

	int CONTROL_EDGE_X = 30;
	int CONTROL_EDGE_Y = 30;

	int iterator_i = 0;
	int iterator_j = 0;

	//DIVISION LINE
	int DIVISIONLINE_L = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10;
	int DIVISIONLINE_U = TABLE_EDGE_X;
	int DIVISIONLINE_R = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10 + 1;
	int DIVISIONLINE_D = WINDOW_H - TABLE_EDGE_X;
	rectangle(DIVISIONLINE_L, DIVISIONLINE_U, DIVISIONLINE_R, DIVISIONLINE_D);

	//----TABLEAREA----

	for (iterator_i = 0; iterator_i < NUM_DAY; ++iterator_i)
	{
		for (iterator_j = 0; iterator_j < NUM_CLASS; ++iterator_j)
		{
			int BLOCK_L = TABLE_EDGE_X + iterator_i * BLOCK_W;
			int BLOCK_U = TABLE_EDGE_Y + iterator_j * BLOCK_H;
			int BLOCK_R = TABLE_EDGE_X + (iterator_i + 1)*BLOCK_W;
			int BLOCK_D = TABLE_EDGE_Y + (iterator_j + 1)*BLOCK_H;
			rectangle(BLOCK_L, BLOCK_U, BLOCK_R, BLOCK_D);
		}
	}

	//----CONTROLAREA----
	
	int LOGO_SIZE = 145;
	int LOGO_L = CONTROLAREA_L + CONTROL_EDGE_X;
	int LOGO_U = CONTROL_EDGE_Y;
	int LOGO_R = LOGO_L + LOGO_SIZE;
	int LOGO_D = LOGO_U + LOGO_SIZE;
	rectangle(LOGO_L, LOGO_U, LOGO_R, LOGO_D);
}

int main()
{
	initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	WindowMain();
	system("PAUSE");
	return 0;
}
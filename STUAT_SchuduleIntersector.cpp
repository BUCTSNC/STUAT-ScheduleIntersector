//STUAT_SchuduleIntersector.cpp
//STUAT
//
//Created by LaoshuBaby on 2020/11/19
//Copyleft © 2020 Student Network Center Of BUCT. All right NOT reserved.
//

#include <iostream>
//#include <sqlite.h>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
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

class BUTTON
{
public:
	//VITAL
	int BUTTON_W;
	int BUTTON_H;
	int BUTTON_L;
	int BUTTON_U;
	int BUTTON_R;
	int BUTTON_D;
	int FLAG_VISIABLE = 0;
	//OPTIONAL
	COLOR16 BUTTON_COLOR;
	TCHAR *BUTTON_TEXT;
	//FUNCTION
	BUTTON()
	{
		BUTTON_INIT(0, 0, 1, 1);
	}
	BUTTON(int L, int U, int R, int D)
	{
		BUTTON_INIT(L, U, R, D);
	}
	void BUTTON_INIT(int L, int U, int R, int D)
	{
		BUTTON_L = L;
		BUTTON_U = U;
		BUTTON_R = R;
		BUTTON_D = D;
		BUTTON_W = BUTTON_R - BUTTON_L;
		BUTTON_H = BUTTON_D - BUTTON_U;
	}
	void setBUTTON(int W, int H)
	{
		BUTTON_W = W;
		BUTTON_H = H;
		//保持左上角不动
		BUTTON_R = BUTTON_L + BUTTON_W;
		BUTTON_D = BUTTON_U + BUTTON_H;
	}
	void setBUTTON_COLOR(COLOR16 COLOR)
	{
		BUTTON_COLOR = COLOR;
	}
	void setBUTTON_TEXT(TCHAR *TEXT)
	{
		BUTTON_TEXT = TEXT;
	}
	int isBUTTON_IN(int X, int Y)
	{
		if (X >= BUTTON_L && X <= BUTTON_R && Y >= BUTTON_U && Y <= BUTTON_D)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void drawBUTTON(int mode=1)
	{
		if (mode)
		{
			rectangle(BUTTON_L, BUTTON_U, BUTTON_R, BUTTON_D);
		}
		else
		{
			solidrectangle(BUTTON_L, BUTTON_U, BUTTON_R, BUTTON_D);
		}
	}
};

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
	int DIVISIONLINE_L = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10;//1295
	int DIVISIONLINE_U = TABLE_EDGE_X;//30
	int DIVISIONLINE_R = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10 + 1;//1296
	int DIVISIONLINE_D = WINDOW_H - TABLE_EDGE_X;//1470
	rectangle(DIVISIONLINE_L, DIVISIONLINE_U, DIVISIONLINE_R, DIVISIONLINE_D);

	//----TABLEAREA----

	//DRAW BLOCKS
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

	//DRAW LOGO
	int LOGO_SIZE = (CONTROLAREA_R - TABLEAREA_R) - 2 * CONTROL_EDGE_X;//145
	int LOGO_L = CONTROLAREA_L + CONTROL_EDGE_X;
	int LOGO_U = CONTROL_EDGE_Y;
	int LOGO_R = LOGO_L + LOGO_SIZE;
	int LOGO_D = LOGO_U + LOGO_SIZE;
	rectangle(LOGO_L, LOGO_U, LOGO_R, LOGO_D);

	//INIT BUTTON POS
	int BUTTON_NUM = 5;
	int DEFAULT_BUTTON_W = LOGO_SIZE;
	int DEFAULT_BUTTON_H = CONTROL_EDGE_Y;
	int DEFAULT_BUTTON_L = LOGO_L;
	int DEFAULT_BUTTON_R = LOGO_R;
	int DEFAULT_BUTTON_U = LOGO_D + CONTROL_EDGE_Y + 200;
	int DEFAULT_BUTTON_EDGE = CONTROL_EDGE_Y;
	BUTTON BUTTON_LIST[5];
	for (iterator_i = 0; iterator_i < BUTTON_NUM; ++iterator_i)
	{
		int TEMP_BUTTON_L = DEFAULT_BUTTON_L;
		int TEMP_BUTTON_U = DEFAULT_BUTTON_U + iterator_i * DEFAULT_BUTTON_H + iterator_i * DEFAULT_BUTTON_EDGE;
		int TEMP_BUTTON_R = DEFAULT_BUTTON_R;
		int TEMP_BUTTON_D = DEFAULT_BUTTON_U + (iterator_i + 1) * DEFAULT_BUTTON_H + iterator_i * DEFAULT_BUTTON_EDGE;
		BUTTON_LIST[iterator_i].BUTTON_INIT(TEMP_BUTTON_L, TEMP_BUTTON_U, TEMP_BUTTON_R, TEMP_BUTTON_D);
		BUTTON_LIST[iterator_i].FLAG_VISIABLE = 1;
		//TCHAR DEFAULT_TEXT[] = { TEXT("SNC") };
		//BUTTON_LIST[iterator_i].setBUTTON_TEXT(&DEFAULT_TEXT);
	}

	//INIT BUTTON TEXT
	//BUTTON_LIST[0].setBUTTON_TEXT("SNC");

	//DRAW BUTTON
	for (iterator_i = 0; iterator_i < BUTTON_NUM; ++iterator_i)
	{
		if (BUTTON_LIST[iterator_i].FLAG_VISIABLE == 1)
		{
			BUTTON_LIST[iterator_i].drawBUTTON();
		}
	}

	//MOUSE DETECTOR
	MOUSEMSG STUAT;
	while (1)
	{
		STUAT = GetMouseMsg();
		switch (STUAT.uMsg)
		{
			case WM_LBUTTONDOWN:
			{
				if (STUAT.x >= LOGO_L && STUAT.x <= LOGO_R && STUAT.y >= LOGO_U && STUAT.y <= LOGO_D)
				{
					cout << "[STUAT] LOGO" << endl;
				}
				else 
				{
					for (iterator_i = 0; iterator_i < BUTTON_NUM; ++iterator_i)
					{
						if (BUTTON_LIST[iterator_i].FLAG_VISIABLE == 1 && BUTTON_LIST[iterator_i].isBUTTON_IN(STUAT.x, STUAT.y))
						{
							cout << "[STUAT] BUTTON " << iterator_i + 1 << " is pressed." << endl;
						}
					}
				}
			}
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
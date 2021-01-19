//main.cpp
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

#include "../Hpp/Basic/MACRO.hpp"
#include "../Hpp/Class/BLOCK.hpp"
#include "../Hpp/Class/BUTTON.hpp"
#include "../Hpp/Function/INIT_FUNC.hpp"

using namespace std;

int FLAG_SCHEDULE_LOADED = 0;
int FLAG_WINDOWMAIN_SHOWING = 0;

int TABLE_EDGE_X = 30;
int TABLE_EDGE_Y = 30;

int CONTROL_EDGE_X = 30;
int CONTROL_EDGE_Y = 30;

int iterator_i = 0;
int iterator_j = 0;

//To make control panal is shared by every window
BUTTON BUTTON_LIST[8];
int BUTTON_VISIABLE_LIST[8] = { 1,1,1,1,1,1,1,1 };

void DRAW_CENTERBOX(int *CENTERBOX_L, int *CENTERBOX_U, int *CENTERBOX_R, int *CENTERBOX_D)
{
	int TABLEAREA_R = 1295;
	*CENTERBOX_L = (0.5 - 0.3)*TABLEAREA_R;
	*CENTERBOX_U = (0.5 - 0.3)*WINDOW_H;
	*CENTERBOX_R = (0.5 + 0.3)*TABLEAREA_R;
	*CENTERBOX_D = (0.5 + 0.3)*WINDOW_H;
	rectangle(*CENTERBOX_L, *CENTERBOX_U, *CENTERBOX_R, *CENTERBOX_D);
}

void INIT_DIVISION_LINE(void)
{
	int DIVISIONLINE_L = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10;//1295
	int DIVISIONLINE_U = TABLE_EDGE_X;//30
	int DIVISIONLINE_R = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10 + 1;//1296
	int DIVISIONLINE_D = WINDOW_H - TABLE_EDGE_X;//1470
	rectangle(DIVISIONLINE_L, DIVISIONLINE_U, DIVISIONLINE_R, DIVISIONLINE_D);
}

void FUNC1(void)
{
	cout << "[FUNC1]" << endl;
	FLAG_WINDOWMAIN_SHOWING = 0;
	INIT_TABLEAREA();
	INIT_DIVISION_LINE();
	//
	int CENTERBOX_L = 0;
	int CENTERBOX_U = 0;
	int CENTERBOX_R = 1;
	int CENTERBOX_D = 1;
	DRAW_CENTERBOX(&CENTERBOX_L, &CENTERBOX_U, &CENTERBOX_R, &CENTERBOX_D);

	int SOURCE_BUTTON_L = CENTERBOX_L + 100;
	int SOURCE_BUTTON_U = CENTERBOX_U + 50;
	int SOURCE_BUTTON_R = CENTERBOX_R - 100;
	int SOURCE_BUTTON_D = SOURCE_BUTTON_U + 50;

	BUTTON SOURCE_FROM_DB(SOURCE_BUTTON_L, SOURCE_BUTTON_U, SOURCE_BUTTON_R, SOURCE_BUTTON_D);
	BUTTON SOURCE_FROM_USERINPUT(0,0,1,1);

	SOURCE_FROM_DB.drawBUTTON();

	MOUSEMSG STUAT;
	while (1)
	{
		STUAT = GetMouseMsg();
		switch (STUAT.uMsg)
		{
		case WM_LBUTTONDOWN:
		{
			//模式选择
			if (SOURCE_FROM_DB.isBUTTON_IN(STUAT.x, STUAT.y))
			{
				cout << "[STUAT] Start to draw db select" << endl;
			}
			else if(SOURCE_FROM_USERINPUT.isBUTTON_IN(STUAT.x, STUAT.y))
			{
				cout << "[STUAT] Start to draw user input panal" << endl;
			}
			//控制面板
			else if (BUTTON_LIST[7].isBUTTON_IN(STUAT.x, STUAT.y))
			{
				void WINDOW_MAIN(void);
				WINDOW_MAIN();
			}
		}
		}
	}

}

void FUNC8(void)
{
	cout << "[FUNC8]" << endl;
	if (FLAG_WINDOWMAIN_SHOWING == 1)
	{
		exit(0);//EXIT PROGRAM
	}
	else
	{
		void WINDOW_MAIN(void);
		WINDOW_MAIN();//BACK TO WINDOW_MAIN
	}
}

void WINDOW_MAIN(void)
{
	FLAG_WINDOWMAIN_SHOWING = 1;

	//----INIT----

	//DEFINE PLAYGROUND
	setfillcolor(BLACK);
	solidrectangle(0, 0, WINDOW_W, WINDOW_H);
	//INIT TABLEAREA
	INIT_TABLEAREA();
	//INIT CONTROLAREA
	INIT_CONTROLAREA();
	//INIT DIVISION_LINE
	INIT_DIVISION_LINE();

	int TABLEAREA_L = 0;
	int TABLEAREA_R = 1295;
	int CONTROLAREA_L = 1296;
	int CONTROLAREA_R = WINDOW_W;

	//----TABLEAREA----

	BLOCK BLOCK_LIST[NUM_DAY][NUM_CLASS];

	//INIT BLOCKS POS
	for (iterator_i = 0; iterator_i < NUM_DAY; ++iterator_i)
	{
		for (iterator_j = 0; iterator_j < NUM_CLASS; ++iterator_j)
		{
			int TEMP_BLOCK_L = TABLE_EDGE_X + iterator_i * BLOCK_W;
			int TEMP_BLOCK_U = TABLE_EDGE_Y + iterator_j * BLOCK_H;
			int TEMP_BLOCK_R = TABLE_EDGE_X + (iterator_i + 1)*BLOCK_W;
			int TEMP_BLOCK_D = TABLE_EDGE_Y + (iterator_j + 1)*BLOCK_H;
			BLOCK_LIST[iterator_i][iterator_j].BLOCK_INIT(TEMP_BLOCK_L, TEMP_BLOCK_U, TEMP_BLOCK_R, TEMP_BLOCK_D);
		}
	}

	//INIT BLOCKS COLOR
	int DEFAULT_R = GetRValue(DARKGRAY);
	int DEFAULT_G= GetGValue(DARKGRAY);
	int DEFAULT_B= GetBValue(DARKGRAY);
	int MIXED_YELLOW_R = (int)DEFAULT_R*0.6 + GetRValue(YELLOW)*0.35 + GetRValue(WHITE)*0.05;
	int MIXED_YELLOW_G = (int)DEFAULT_G*0.6 + GetGValue(YELLOW)*0.35 + GetGValue(WHITE)*0.05;
	int MIXED_YELLOW_B = (int)DEFAULT_B*0.6 + GetBValue(YELLOW)*0.35 + GetBValue(WHITE)*0.05;
	COLORREF MIXED_YELLOW = RGB(MIXED_YELLOW_R, MIXED_YELLOW_G, MIXED_YELLOW_B);

	//DRAW BLOCKS
	for (iterator_i = 0; iterator_i < NUM_DAY; ++iterator_i)
	{
		for (iterator_j = 0; iterator_j < NUM_CLASS; ++iterator_j)
		{
			BLOCK_LIST[iterator_i][iterator_j].drawBLOCK(1, MIXED_YELLOW);
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
	int BUTTON_NUM = 8;
	int DEFAULT_BUTTON_W = LOGO_SIZE;
	int DEFAULT_BUTTON_H = CONTROL_EDGE_Y;
	int DEFAULT_BUTTON_L = LOGO_L;
	int DEFAULT_BUTTON_R = LOGO_R;
	int DEFAULT_BUTTON_U = LOGO_D + CONTROL_EDGE_Y + 90;
	int DEFAULT_BUTTON_EDGE = CONTROL_EDGE_Y;
	for (iterator_i = 0; iterator_i < BUTTON_NUM; ++iterator_i)
	{
		int TEMP_BUTTON_L = DEFAULT_BUTTON_L;
		int TEMP_BUTTON_U = DEFAULT_BUTTON_U + iterator_i * DEFAULT_BUTTON_H + iterator_i * DEFAULT_BUTTON_EDGE;
		int TEMP_BUTTON_R = DEFAULT_BUTTON_R;
		int TEMP_BUTTON_D = DEFAULT_BUTTON_U + (iterator_i + 1) * DEFAULT_BUTTON_H + iterator_i * DEFAULT_BUTTON_EDGE;
		BUTTON_LIST[iterator_i].BUTTON_INIT(TEMP_BUTTON_L, TEMP_BUTTON_U, TEMP_BUTTON_R, TEMP_BUTTON_D);
		BUTTON_LIST[iterator_i].FLAG_VISIABLE = BUTTON_VISIABLE_LIST[iterator_i];
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
							if (iterator_i < 0 || iterator_i >= BUTTON_NUM)
							{
								cout << "[STUAT] invaild press." << endl;
							}
							else if (iterator_i == 1 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
								FUNC1();
							}
							else if (iterator_i == 2 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 3 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 4 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 5 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 6 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 7 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
							}
							else if (iterator_i == 8 - 1)
							{
								cout << "[STUAT] FUNCTION " << iterator_i + 1 << endl;
								//CALLFUNC
								FUNC8();
							}
							else
							{
								cout << "[STUAT] unexcepted press." << endl;
							}
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
	WINDOW_MAIN();
	system("PAUSE");
	return 0;
}
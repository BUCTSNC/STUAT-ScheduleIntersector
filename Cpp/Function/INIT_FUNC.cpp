#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

#include "../../Hpp/Basic/MACRO.hpp"
//#include "../../Hpp/Basic/VARIABLE.hpp"
#include "../../Hpp/Class/BLOCK.hpp"
#include "../../Hpp/Class/BUTTON.hpp"

#pragma once

//int TABLE_EDGE_X = 30;
//int TABLE_EDGE_Y = 30;
//
//int CONTROL_EDGE_X = 30;
//int CONTROL_EDGE_Y = 30;

void INIT_TABLEAREA(void)
{
	setfillcolor(DARKGRAY);
	int TABLEAREA_L = 0;
	int TABLEAREA_U = 0;
	int TABLEAREA_R = 1295;
	int TABLEAREA_D = WINDOW_H;
	solidrectangle(TABLEAREA_L, TABLEAREA_U, TABLEAREA_R, TABLEAREA_D);
}

void INIT_CONTROLAREA(void)
{
	setfillcolor(LIGHTGRAY);
	int CONTROLAREA_L = 1296;
	int CONTROLAREA_U = 0;
	int CONTROLAREA_R = WINDOW_W;
	int CONTROLAREA_D = WINDOW_H;
	solidrectangle(CONTROLAREA_L, CONTROLAREA_U, CONTROLAREA_R, CONTROLAREA_D);
}

void INIT_DIVISION_LINE(void)
{
	int DIVISIONLINE_L = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10;//1295
	int DIVISIONLINE_U = TABLE_EDGE_X;//30
	int DIVISIONLINE_R = TABLE_EDGE_X * 2 + BLOCK_W * NUM_DAY + 10 + 1;//1296
	int DIVISIONLINE_D = WINDOW_H - TABLE_EDGE_X;//1470
	rectangle(DIVISIONLINE_L, DIVISIONLINE_U, DIVISIONLINE_R, DIVISIONLINE_D);
}
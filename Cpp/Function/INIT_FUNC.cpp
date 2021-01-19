#include <iostream>
#include <graphics.h>
#include <conio.h>

#include "../../Hpp/Basic/MACRO.hpp"
#include "../../Hpp/Class/BLOCK.hpp"
#include "../../Hpp/Class/BUTTON.hpp"

#pragma once

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


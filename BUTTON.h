#include "MACRO.h"

#pragma once

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
	COLORREF BUTTON_COLOR;
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
		//Keep the upper left corner static.
		BUTTON_R = BUTTON_L + BUTTON_W;
		BUTTON_D = BUTTON_U + BUTTON_H;
	}
	void setBUTTON_COLOR(COLORREF COLOR)
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
	void drawBUTTON(int mode = 1)
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
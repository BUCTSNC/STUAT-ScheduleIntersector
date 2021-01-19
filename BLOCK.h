#pragma once

class BLOCK
{
public:
	//VITAL
	int BLOCK_L;
	int BLOCK_U;
	int BLOCK_R;
	int BLOCK_D;
	//OPTIONAL
	int DEFAULT_BLOCK_W = BLOCK_W;
	int DEFAULT_BLOCK_H = BLOCK_H;
	COLORREF BLOCK_COLOR;
	//FUNCTION
	BLOCK()
	{
		BLOCK_INIT(0, 0, 1, 1);
	}
	BLOCK(int L, int U, int R, int D)
	{
		BLOCK_INIT(L, U, R, D);
	}
	void BLOCK_INIT(int L, int U, int R, int D)
	{
		BLOCK_L = L;
		BLOCK_U = U;
		BLOCK_R = R;
		BLOCK_D = D;
	}
	void drawBLOCK(int mode = 1, COLORREF COLOR = RED)
	{
		if (mode)
		{
			rectangle(BLOCK_L, BLOCK_U, BLOCK_R, BLOCK_D);
		}
		else
		{
			setfillcolor(COLOR);
			solidrectangle(BLOCK_L, BLOCK_U, BLOCK_R, BLOCK_D);
		}
	}
};
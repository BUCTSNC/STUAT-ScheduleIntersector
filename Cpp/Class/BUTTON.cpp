#include "../../Hpp/Class/BUTTON.hpp"

BUTTON::BUTTON()
{
	BUTTON_INIT(0, 0, 1, 1);
}
BUTTON::BUTTON(int L, int U, int R, int D)
{
	BUTTON_INIT(L, U, R, D);
}

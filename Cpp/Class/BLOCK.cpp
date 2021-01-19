#include "../../Hpp/Class/BLOCK.hpp"

BLOCK::BLOCK()
{
	BLOCK_INIT(0, 0, 1, 1);
}
BLOCK::BLOCK(int L, int U, int R, int D)
{
	BLOCK_INIT(L, U, R, D);
}
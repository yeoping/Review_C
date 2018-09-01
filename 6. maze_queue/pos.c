#include "pos.h"

int offset[][2] = { {-1,0},{0,1},{1,0},{0,-1} };

Position move_to(Position cur, int dir)
{
	Position next;
	next.x = cur.x + offset[dir][0];
	next.y = cur.y + offset[dir][1];
	return next;
}
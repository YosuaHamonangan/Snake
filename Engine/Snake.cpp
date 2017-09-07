#include "Snake.h"

snake::snake()
{
	init();
}

void snake::init()
{
	x.clear();
	y.clear();
	for (int n = 0; n < length; n++)
	{
		x.push_front(xInit);
		y.push_front(yInit);
	}
}

void snake::DrawSnake(Graphics& gfx, arena& arn)
{
	int X, Y;

	for (int n = 0; n < length; n++)
	{
		X = x.front();
		x.pop_front();
		Y = y.front();
		y.pop_front();

		arn.DrawSegment(X, Y, gfx, 0, 255, 0);
		x.push_back(X);
		y.push_back(Y);
	}
}

void snake::SetDirection(int dir)
{
	if (Direction == 0 || dir % 2 != Direction % 2) Direction = dir;
}

void snake::MoveSnake()
{
	int X = x.front();
	int Y = y.front();

	if (Direction == MOVERIGHT) X++;
	if (Direction == MOVELEFT) X--;
	if (Direction == MOVEDOWN) Y++;
	if (Direction == MOVEUP) Y--;

	x.push_front(X);
	lastx = x.back();
	x.pop_back();

	y.push_front(Y);
	lasty = y.back();
	y.pop_back();
}

void snake::AddLength()
{
	length++;
	x.push_back(lastx);
	y.push_back(lasty);
}

bool snake::isDead()
{
	if (y.front() == arena::Height || y.front() < 0) return true;
	else if (x.front() == arena::Width || x.front() < 0) return true;
	else if (CompareToBody(x.front(), y.front()) && Direction != 0) return true;
	else return false;
}

bool snake::CompareToBody(int X, int Y)
{
	bool hit = false;
	x.push_back(x.front());
	x.pop_front();
	y.push_back(y.front());
	y.pop_front();
	
	for (int n = 1; n < length; n++)
	{
		if (X == x.front() && Y == y.front()) hit = true;
		x.push_back(x.front());
		x.pop_front();
		y.push_back(y.front());
		y.pop_front();
	}
	return hit;
}

bool snake::CompareToHead(int X, int Y)
{
	if (X == x.front() && Y == y.front()) return true;
	else return false;
}

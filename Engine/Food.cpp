#include "Food.h"

food::food(snake& snk)
{
	srand(time(NULL));
	do
	{
		x = rand() % arena::Width;
		y = rand() % arena::Height;
	} while (snk.CompareToHead(x,y));
}

void food::DrawFood(Graphics& gfx, arena& arn)
{
	arn.DrawSegment(x, y, gfx, 255, 0, 0);
}

void food::Update(snake& snk)
{
	do
	{
		x = rand() % arena::Width;
		y = rand() % arena::Height;
	} while (snk.CompareToBody(x, y) || snk.CompareToHead(x, y));
}

bool food::isEaten(snake & snk)
{
	return snk.CompareToHead(x, y);
}




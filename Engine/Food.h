#pragma once
#include <time.h>
#include <stdlib.h>
#include "Graphics.h"
#include "Snake.h"

class food
{
public:
	food(snake& snk);
	void DrawFood(Graphics& gfx, arena& arn);
	void Update(snake& snk);
	bool isEaten(snake& snk);
private:
	const int Segment = arena::Segment;
	int x, y;
};
#include "Arena.h"

void arena::DrawGrid(Graphics& gfx)
{
	for (int x = x0; x < xf; x++)
	{
		gfx.PutPixel(x, y0 - 1, 0, 0, 255);
		gfx.PutPixel(x, yf + 1, 0, 0, 255);
	}
	for (int y = y0-1; y <= yf; y++)
	{
		gfx.PutPixel(x0 - 1, y, 0, 0, 255);
		gfx.PutPixel(xf - 1, y, 0, 0, 255);
	}
}

void arena::DrawSegment(int X, int Y, Graphics& gfx, int r, int g, int b)
{
	for (int n = 0; n < Segment; n++)
	{
		for (int m = 0; m < Segment; m++)
		{
			gfx.PutPixel(x0 + X*Segment + n, y0 + Y*Segment + m, r, g, b);
		}
	}
}

void arena::AddScore()
{
	Score++;
}

void arena::ResetScore()
{
	Score = 0;
}

void arena::DisplayScore(Graphics& gfx)
{
	for (int n = 0; n < Score; n++)
	{
		for (int m = 0; m < 10; m++)
		{
			gfx.PutPixel(10 + n * 3, 10 + m, 255, 255, 255);
		}
	}
}

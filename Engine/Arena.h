#pragma once
#include "Graphics.h"

class arena
{
public:
	void DrawGrid(Graphics& gfx);
	void DrawSegment(int X, int Y, Graphics& gfx, int r, int g, int b);
	void AddScore();
	void ResetScore();
	void DisplayScore(Graphics& gfx);

	int Score = 0;

	static const int Height = 40;
	static const int Width = 60;
	static const int Segment = 10;
private:
	static const int w = Width*Segment;
	static const int h = Height*Segment;
public:
	static const int x0 = (Graphics::ScreenWidth - w) / 2;
	static const int y0 = (Graphics::ScreenHeight - h) / 2;
private:
	static const int xf = x0 + w;
	static const int yf = y0 + h;
};
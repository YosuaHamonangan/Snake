#pragma once
#include <list>
#include "Graphics.h"
#include "Arena.h"
#define MOVEUP 1
#define MOVEDOWN 3
#define MOVERIGHT 2
#define MOVELEFT 4

class snake
{
public:
	snake();
	void init();
	void DrawSnake(Graphics& gfx, arena& arn);
	void SetDirection(int key);
	void MoveSnake();
	void AddLength();
	bool isDead();
	bool CompareToBody(int X, int Y);
	bool CompareToHead(int X, int Y);

private:
	list<int> x;
	list<int> y;
	const int Segment = arena::Segment;

	int xInit = 3, yInit = 3;
	int length = 5;
	int Direction = 0;
	bool PrevDirection;
	int lastx, lasty;
};
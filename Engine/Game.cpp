/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	snk(),
	fd(snk)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateSnake()
{
	snk.MoveSnake();
	over = snk.isDead();
	if (fd.isEaten(snk))
	{
		snk.AddLength();
		fd.Update(snk);
		arn.AddScore();
	}
}

void Game::GetInput()
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) snk.SetDirection(MOVERIGHT);
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) snk.SetDirection(MOVELEFT);
	else if (wnd.kbd.KeyIsPressed(VK_DOWN)) snk.SetDirection(MOVEDOWN);
	else if (wnd.kbd.KeyIsPressed(VK_UP)) snk.SetDirection(MOVEUP);

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		snk.init();
		snk.SetDirection(MOVERIGHT);
		fd.Update(snk);
		arn.ResetScore();
		over = false;
	}
}

void Game::UpdateModel()
{
	GetInput();
	if (!over && step == 0) UpdateSnake();
	step++;
	if (step == MaxStep) step = 0;
}

void Game::ComposeFrame()
{
	arn.DrawGrid(gfx);
	if (!over)
	{
		snk.DrawSnake(gfx, arn);
		fd.DrawFood(gfx, arn);
		arn.DisplayScore(gfx);
	}
	else
	{
		for (int n = 0; n < gfx.ScreenHeight; n++)
		{
			gfx.PutPixel(n, n, 255, 255, 255);
			gfx.PutPixel(gfx.ScreenHeight - n, n, 255, 255, 255);
		}
	}
}

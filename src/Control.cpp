#include "Control.h"
#include "Game.h"
#include "Utils.h"

void Game::HandleInput()
{
	if (Utils::IsKeyDown(Key_Quit))
	{
		Game::Quit();
	}
	else if (Utils::IsKeyDown(Key_Rotate))
	{
		Game::Rotate();
	}
	else if (Utils::IsKeyDown(Key_Down))
	{
		Game::MoveDown();
	}
	else if (Utils::IsKeyDown(Key_Left))
	{
		Game::MoveLeft();
	}
	else if (Utils::IsKeyDown(Key_Right))
	{
		Game::MoveRight();
	}
}
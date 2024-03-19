#include "Control.h"
#include "Game.h"
#include "Utils.h"

namespace Game
{
	void HandleInput()
	{
		if (Utils::IsKeyDown(Key_Quit))
		{
			Quit();
		}
		else if (Utils::IsKeyDown(Key_Rotate))
		{
			Rotate();
		}
		else if (Utils::IsKeyDown(Key_Down))
		{
			MoveDown();
		}
		else if (Utils::IsKeyDown(Key_Left))
		{
			MoveLeft();
		}
		else if (Utils::IsKeyDown(Key_Right))
		{
			MoveRight();
		}
	}
} // namespace Game
#include "Control.h"
#include "Game.h"

namespace Game
{
	std::unordered_map<int, std::pair<bool, bool>> keyStates{
		{ Key_Quit, { false, false } },
		{ Key_Rotate_L, { false, false } },
		{ Key_Rotate_R, { false, false } },
		{ Key_Rotate_RD, { false, false } },
		{ Key_Hold, { false, false } },
		{ Key_Down, { false, false } },
		{ Key_Left, { false, false } },
		{ Key_Right, { false, false } },
		{ Key_Space, { false, false } },
	};

	void UpdateKeyState()
	{

		for (auto& [key, state] : keyStates)
		{
			state.first = state.second;

			static const int Mask = 0x8000;
			state.second = GetKeyState(key) & Mask;
		}
	}

	bool IsKeyDown(int vKey)
	{
		return !keyStates[vKey].first && keyStates[vKey].second;
	}

	void HandleInput()
	{
		UpdateKeyState();
		if (IsKeyDown(Key_Quit))
		{
			Quit();
		}
		else if (IsKeyDown(Key_Rotate_L))
		{
			RotateL();
		}
		else if (IsKeyDown(Key_Rotate_R))
		{
			RotateR();
		}
		else if (IsKeyDown(Key_Rotate_RD))
		{
			RotateRD();
		}
		else if (IsKeyDown(Key_Hold))
		{
			HoldPiece();
		}
		else if (IsKeyDown(Key_Down))
		{
			MoveDown();
		}
		else if (IsKeyDown(Key_Left))
		{
			MoveLeft();
		}
		else if (IsKeyDown(Key_Right))
		{
			MoveRight();
		}
		else if (IsKeyDown(Key_Space))
		{
			Drop();
		}
	}
} // namespace Game
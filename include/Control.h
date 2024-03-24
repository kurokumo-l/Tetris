#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <Windows.h>
#include <winuser.h>
#include <unordered_map>

namespace Game
{

	constexpr int Key_Quit = 'Q';
	constexpr int Key_Rotate = 'W';
	constexpr int Key_Down = 'S';
	constexpr int Key_Left = 'A';
	constexpr int Key_Right = 'D';
	constexpr int Key_Space = VK_SPACE;

	extern std::unordered_map<int, std::pair<bool, bool>> keyStates;

	void UpdateKeyState();
	bool IsKeyDown(int vKey);
	void HandleInput();
} // namespace Game
#endif
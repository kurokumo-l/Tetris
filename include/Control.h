#ifndef _CONTROL_H_
#define _CONTROL_H_

#include <Windows.h>
#include <winuser.h>
namespace Game
{

	constexpr int Key_Quit = 'Q';
	constexpr int Key_Rotate = 'W';
	constexpr int Key_Down = 'S';
	constexpr int Key_Left = 'A';
	constexpr int Key_Right = 'D';
	constexpr int Key_Space = VK_SPACE;

	void HandleInput();
} // namespace Game
#endif
#ifndef _CONTROL_H_
#define _CONTROL_H_

namespace Game
{

	constexpr int Key_Quit = 'Q';
	constexpr int Key_Rotate = 'W';
	constexpr int Key_Down = 'S';
	constexpr int Key_Left = 'A';
	constexpr int Key_Right = 'D';

	void HandleInput();
} // namespace Game
#endif
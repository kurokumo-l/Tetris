#ifndef _CONTROL_H_
#define _CONTROL_H_

namespace Game
{

constexpr int KEY_QUIT = 'Q';
constexpr int KEY_Rotate = 'W';
constexpr int KEY_Down = 'S';
constexpr int KEY_Left = 'A';
constexpr int KEY_Right = 'D';

void HandleInput();
} // namespace Game
#endif
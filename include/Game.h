#ifndef _GAME_H_
#define _GAME_H_

namespace Game
{

	extern bool isRunning;

	void Init();
	void Quit();
	void Rotate();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
} // namespace Game

#endif
#ifndef _GAME_H_
#define _GAME_H_

#include "Tetromio.h"
namespace Game
{

	extern bool isRunning;

	extern int currentRow;
	extern int currentCol;
    extern Tetromino currentTetromino;

	void Init();
	void Quit();
	void Rotate();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
} // namespace Game

#endif
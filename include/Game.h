#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Piece.h"
#include <chrono>
namespace Game
{
	constexpr int					 RowNum = 22;
	constexpr int					 ColNum = 10;
	extern bool						 isRunning;
	extern Board					 playfield;
	extern Board					 frame;
	extern Piece					 onePiece;
	extern std::chrono::microseconds duration;

	void Init();
	void Process();
	void Render();
	void Quit();

	Piece Pick();

	void Lock();
	void Clear();

	void Rotate();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Drop();
} // namespace Game

#endif
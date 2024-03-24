#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Piece.h"
#include "Tetromio.h"
#include <chrono>
#include <queue>
namespace Game
{
	constexpr int					 RowNum = 22;
	constexpr int					 ColNum = 10;
	extern bool						 isRunning;
	extern Board					 playfield;
	extern Board					 frame;
	extern Piece					 onePiece;
	extern std::queue<TetrominoSet>	 previewQuene;
	extern std::chrono::microseconds duration;

	void Init();
	void Process();
	void Render();
	void Quit();

	Piece Pick();
    void GetPreview();

	void Lock();
	void Clear();

	void Rotate();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Drop();

    void PlacePiece(Board& board, const Piece& piece);
} // namespace Game

#endif
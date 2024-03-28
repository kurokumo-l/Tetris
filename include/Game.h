#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Piece.h"
#include "Tetromio.h"
#include <chrono>
#include <fstream>
#include <queue>
namespace Game
{
	constexpr int					 RowNum = 22;
	constexpr int					 ColNum = 10;
	extern bool						 isRunning;
	extern Board					 playfield;
	extern Board					 frame;
	extern Piece					 onePiece;
	extern bool						 isEnd;
	extern bool						 isHolding;
	extern bool						 isPrepareToLock;
	extern std::queue<TetrominoSet>	 holdQuene;
	extern std::queue<TetrominoSet>	 previewQuene;
	extern std::chrono::microseconds duration;
	extern int						 score;
	extern int						 level;
	extern int						 lines;

	void Init();
	void Process();
	void Render();
	void Quit();

	void LevelUp();

	void LoadMap(std::fstream& file);

	Piece Pick();
	void  GetPreview();
	void  HoldPiece();

	void Lock();
	void Clear();

	void RotateL();
	void RotateR();
	void RotateRD();

	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Drop();

	void PlacePiece(Board& board, const Piece& piece);
} // namespace Game

#endif
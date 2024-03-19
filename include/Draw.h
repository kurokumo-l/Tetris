#ifndef _DRAW_H_
#define _DRAW_H_

#include "Board.h"
#include "Tetromio.h"
#include <string>

namespace Draw
{
	struct Rect
	{
		int top;
		int left;
		int width;
		int height;
	};
	int	 ColCast(int col);
	void DrawWindow(Rect rect, const std::string& title);
	void DrawTetromino(int top, int left, const Game::TetrominoSet& t, int index);
    void DrawFrame(const Game::Board &frame, int top, int left);
} // namespace Draw

#endif
#ifndef _DRAW_H_
#define _DRAW_H_

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
    void DrawTetromino(int top, int left, const Game::Tetromino &t);
} // namespace Draw

#endif
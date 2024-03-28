#ifndef _DRAW_H_
#define _DRAW_H_

#include "Board.h"
#include "Tetromio.h"
#include <queue>
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
	void DrawBoard(const Game::Board& board, int top, int left, const Game::Board& buffer, const std::string& blank = "  ");
	void DrawFrame(const Game::Board& frame, int top, int left);
    void DrawHold(std::queue<Game::TetrominoSet> holdQuene, int top, int left);
    void DrawPreview(std::queue<Game::TetrominoSet> previewQuene, int top, int left);
} // namespace Draw

#endif
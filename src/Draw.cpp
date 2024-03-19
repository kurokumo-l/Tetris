#include "Draw.h"
#include "Board.h"
#include "Game.h"
#include "Terminal.h"
#include <iostream>
#include <ranges>
#include <string>

namespace Draw
{
	int ColCast(int col)
	{
		return col * 2 - 1;
	}

	void DrawWindow(Rect rect, const std::string& title)
	{
		int top = rect.top;
		int left = rect.left;
		int width = rect.width;
		int height = rect.height;
		// 第一行
		TerminalControl::MoveCursor(top, ColCast(left));
		std::cout << " ┌";
		for (int i = 1; i < width - 1; i++)
		{
			std::cout << "──";
		}
		std::cout << "┐ ";

		// 标题
		TerminalControl::MoveCursor(top, ColCast((width - (int)title.length()) / 2 + left + 1));
		std::cout << title;

		// 第二行到倒数第二行
		for (int i = 1; i < height - 1; i++)
		{
			TerminalControl::MoveCursor(top + i, ColCast(left));
			std::cout << " │";
			for (int j = 1; j < width - 1; j++)
			{
				std::cout << "  ";
			}
			std::cout << "│ ";
		}

		// 最后一行
		TerminalControl::MoveCursor(top + height - 1, ColCast(left));
		std::cout << " └";
		for (int i = 1; i < width - 1; i++)
		{
			std::cout << "──";
		}
		std::cout << "┘ ";
	}

	void DrawTetromino(int top, int left, const Game::TetrominoSet& t, int index)
	{
		TerminalControl::MoveCursor(top, ColCast(left));
		TerminalControl::SetBackCorlor(t[index][0].second);
		std::cout << "  ";

		for (int i = 1; i < 4; i++)
		{
			TerminalControl::MoveCursor(top - t[index][i].second, ColCast(left + t[index][i].first));
			std::cout << "  ";
		}

		TerminalControl::ResetCorlor();
	}

	void DrawFrame(const Game::Board& frame, int top, int left)
	{
		for (auto x : std::ranges::views::iota(0, Game::ColNum))
		{
			for (auto y : std::ranges::views::iota(0, Game::RowNum - 2))
			{
				int row = top + Game::RowNum - 2 - y - 1;
				int col = left + x;
				TerminalControl::MoveCursor(row, ColCast(col));
				if (frame[x][y] > 0)
				{
					TerminalControl::ResetCorlor();
					TerminalControl::SetBackCorlor(frame[x][y]);
					std::cout << "  ";
				}
				else if (frame[x][y] < 0)
				{
					TerminalControl::ResetCorlor();
					TerminalControl::SetForeCorlor(-frame[x][y]);
					std::cout << "◣";
				}
                else {
                    TerminalControl::ResetCorlor();
                    std::cout << " ·";
                }
			}
		}
	}
} // namespace Draw
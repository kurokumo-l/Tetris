#include "Draw.h"
#include "Board.h"
#include "Game.h"
#include "Terminal.h"
#include <climits>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

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

	void DrawFrame(const Game::Board& frame, int top, int left)
	{
		static Game::Board buffer(frame.size(), std::vector<int>(frame[0].size(), INT_MIN));

		for (auto x : std::ranges::views::iota(0, Game::ColNum))
		{
			for (auto y : std::ranges::views::iota(0, Game::RowNum - 2))
			{
				if (buffer[y][x] == frame[y][x])
				{
					continue;
				}
				buffer[y][x] = frame[y][x];

				int row = top + Game::RowNum - 2 - y - 1;
				int col = left + x;
				TerminalControl::MoveCursor(row, ColCast(col));
				if (frame[y][x] > 0)
				{
					TerminalControl::SetBackCorlor(frame[y][x]);
					std::cout << "  ";
				}
				else if (frame[y][x] < 0)
				{
					TerminalControl::SetForeCorlor(-frame[y][x]);
					std::cout << "◣◥";
				}
				else
				{
					std::cout << "・";
				}
				TerminalControl::ResetCorlor();
			}
		}
	}
} // namespace Draw
#include "Draw.h"
#include "Board.h"
#include "Game.h"
#include "Piece.h"
#include "Terminal.h"
#include "Tetromio.h"
#include <climits>
#include <iostream>
#include <queue>
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
	void DrawBoard(const Game::Board& board, int top, int left, Game::Board* buffer, const std::string& blank = "  ")
	{
		for (auto y : std::ranges::views::iota(0, (int)board.size()))
		{
			for (auto x : std::ranges::views::iota(0, (int)board.front().size()))
			{
				if ((*buffer)[y][x] == board[y][x])
				{
					continue;
				}
				(*buffer)[y][x] = board[y][x];

				int row = top + (int)board.size() - y - 1;
				int col = left + x;
				TerminalControl::MoveCursor(row, ColCast(col));
				if (board[y][x] > 0)
				{
					TerminalControl::SetBackCorlor(board[y][x]);
					std::cout << "  ";
				}
				else if (board[y][x] < 0)
				{
					TerminalControl::SetForeCorlor(-board[y][x]);
					std::cout << "◣◥";
				}
				else
				{
					std::cout << blank;
				}
				TerminalControl::ResetCorlor();
			}
		}
	}

	void DrawFrame(const Game::Board& frame, int top, int left)
	{
		static Game::Board buffer(frame.size(), std::vector<int>(frame.front().size(), INT_MIN));

		Game::Board tempFrame = { frame.begin(), frame.begin() + Game::RowNum - 2 };

		DrawBoard(tempFrame, top, left, &buffer, "\u30fb");
	}

	void DrawPreview(std::queue<Game::TetrominoSet> previewQuene, int top, int left)
	{
		Game::Board preview{ 15, std::vector<int>(6, 0) };
		static Game::Board buffer(preview.size(), std::vector<int>(preview.front().size(), INT_MIN));

		for (int y = 12; !previewQuene.empty(); y -= 3)
		{
			Game::Piece p = { previewQuene.front(), 0, { 2, y }, &preview };
			Game::PlacePiece(preview, p);
			previewQuene.pop();
		}
		DrawBoard(preview, top, left, &buffer);
	}
} // namespace Draw
#include "Draw.h"
#include "Terminal.h"
#include <iostream>
#include <string>

int Draw::ColCast(int col)
{
	return col * 2 - 1;
}

void Draw::DrawWindow(Draw::Rect rect, const std::string& title)
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

void Draw::DrawBlock()
{
	TerminalControl::ResetCorlor();
	std::cout << "  ";
}

void Draw::DrawBlock(int color)
{
	TerminalControl::SetBackCorlor(color);
	std::cout << "  ";
	TerminalControl::ResetCorlor();
}

void Draw::DrawTetromino(int top, int left, const Game::Tetromino& t)
{
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			TerminalControl::MoveCursor(top + i, ColCast(left + j));
			if (t[i][j] != 0)
			{
				DrawBlock(t[i][j]);
			}
			else
			{
				DrawBlock();
			}
		}
	}
}
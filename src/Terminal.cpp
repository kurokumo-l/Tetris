#include "Terminal.h"
#include <iostream>

namespace TerminalControl
{
	void MoveCursor(int row, int col)
	{
		std::cout << CSI << std::format("{};{}H", row, col);
	}

	void SetForeCorlor(int id)
	{
		std::cout << CSI << std::format("38;5;{}m", id);
	}

	void SetBackCorlor(int id)
	{
		std::cout << CSI << std::format("48;5;{}m", id);
	}

	void CleanScreen()
	{
		std::cout << CSI << "2J";
	}

	void ResetCorlor()
	{
		std::cout << CSI << "0m";
	}

	void HideCursor()
	{
		std::cout << CSI << "?25l";
	}

	void ShowCursor()
	{
		std::cout << CSI << "?25h";
	}
} // namespace TerminalControl
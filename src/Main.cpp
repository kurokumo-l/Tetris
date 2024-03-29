#include "Corlor.h"
#include "Draw.h"
#include "Game.h"
#include "Terminal.h"
#include "Utils.h"
#include <format>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <winnls.h>

using namespace std::chrono_literals;

// 当前方块
constexpr Draw::Rect HoldRect = { 1, 1, 9, 6 };
// 游戏状态面板
constexpr Draw::Rect StatuRect = { 7, 1, 9, 16 };

// 游戏主窗口
constexpr Draw::Rect GameRect = { 1, 10, 12, 22 };

// 接下来的方块
constexpr Draw::Rect NextRect = { 1, 22, 8, 18 };
// 信息面板
constexpr Draw::Rect InfoRect = { 19, 22, 8, 4 };

constexpr Draw::Rect EndRect = { 9, 12, 8, 3 };

void Init()
{
	SetConsoleOutputCP(CP_UTF8);
	Game::Init();

	TerminalControl::HideCursor();
	TerminalControl::CleanScreen();
	Draw::DrawWindow(HoldRect, "Hold");
	Draw::DrawWindow(StatuRect, "Statu");
	Draw::DrawWindow(GameRect, "Tetrsds");
	Draw::DrawWindow(NextRect, "Next");
	Draw::DrawWindow(InfoRect, "Info");
}

void Loop()
{
	while (Game::isRunning)
	{
		Game::Process();
		Game::Render();
		Draw::DrawFrame(Game::frame, GameRect.top + 1, GameRect.left + 1);
		Draw::DrawHold(Game::holdQuene, HoldRect.top + 1, HoldRect.left + 1);
		Draw::DrawPreview(Game::previewQuene, NextRect.top + 1, NextRect.left + 1);

		TerminalControl::MoveCursor(StatuRect.top + 3, Draw::ColCast(StatuRect.left + 2));
		std::cout << std::format("FPS:{}", Utils::FPS());
		TerminalControl::MoveCursor(StatuRect.top + 5, Draw::ColCast(StatuRect.left + 2));
		std::cout << std::format("Score:{}", Game::score);
		TerminalControl::MoveCursor(StatuRect.top + 6, Draw::ColCast(StatuRect.left + 2));
		std::cout << std::format("Level:{}", Game::level);
		TerminalControl::MoveCursor(StatuRect.top + 7, Draw::ColCast(StatuRect.left + 2));
		std::cout << std::format("Lines:{}", Game::lines);

		if (Game::isEnd)
		{
			Draw::DrawWindow(EndRect, "");
			TerminalControl::MoveCursor(EndRect.top + 1, Draw::ColCast(EndRect.left + 1));
			TerminalControl::SetForeCorlor(Corlor::Red);
			std::cout << " Game Over! ";
            TerminalControl::ResetCorlor();
		}

		std::this_thread::sleep_for(16ms);
	}
}

void Exit()
{
	TerminalControl::CleanScreen();
	TerminalControl::ResetCorlor();
	TerminalControl::MoveCursor(1, 1);
	std::cout << "Bye!\n";
	TerminalControl::ShowCursor();
}

int main()
{
	Init();
	Loop();
	Exit();
}
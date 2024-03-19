#include "Control.h"
#include "Draw.h"
#include "Game.h"
#include "Terminal.h"
#include "Utils.h"
#include <format>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

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

void Init()
{
	std::locale::global(std::locale("zh_CN.UTF-8"));

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
		// Draw::DrawWindow(HoldRect, "Hold");
		// Draw::DrawWindow(StatuRect, "Statu");
		// Draw::DrawWindow(GameRect, "Tetrsds");
		// Draw::DrawWindow(NextRect, "Next");
		// Draw::DrawWindow(InfoRect, "Info");
        Game::Process();
		Draw::DrawFrame(Game::frame, GameRect.top + 1, GameRect.left + 1);

		TerminalControl::MoveCursor(StatuRect.top + 3, Draw::ColCast(StatuRect.left + 1));
		std::cout << std::format("FPS:{}", Utils::FPS());

		std::this_thread::sleep_for(100ms);
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
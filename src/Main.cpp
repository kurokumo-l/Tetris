#include "Control.h"
#include "Draw.h"
#include "Game.h"
#include "Terminal.h"
#include "Utils.h"
#include <format>
#include <iostream>
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

	TerminalControl::HideCursor();
	TerminalControl::CleanScreen();

	// 当前方块
	Draw::DrawWindow(HoldRect, "Hold");
	// 游戏状态面板
	Draw::DrawWindow(StatuRect, "Statu");

	// 游戏主窗口
	Draw::DrawWindow(GameRect, "Tetris");

	// 接下来的方块
	Draw::DrawWindow(NextRect, "Next");
	// 信息面板
	Draw::DrawWindow(InfoRect, "Info");

	Game::Init();
}

void Loop()
{
	int x = 15;
	int y = 18;
	while (Game::isRunning)
	{
		Game::HandleInput();

		TerminalControl::MoveCursor(10, Draw::ColCast(3));
		std::cout << std::format("FPS:{}", Utils::FPS());
		TerminalControl::MoveCursor(y, Draw::ColCast(x));
		TerminalControl::SetBackCorlor(214);
		std::cout << "  ";
		TerminalControl::ResetCorlor();
		std::this_thread::sleep_for(100ms);
		// TerminalControl::CleanScreen();
		// y = (y + 1) % 15;
	}
}

void Exit()
{
	TerminalControl::CleanScreen();
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
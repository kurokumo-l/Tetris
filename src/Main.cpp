#include "Draw.h"
#include "Terminal.h"
#include "utils.h"
#include <format>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void Init()
{
    std::locale::global(std::locale("zh_CN.UTF-8"));

    TerminalControl::HideCursor();
    TerminalControl::CleanScreen();

    // 当前方块
    Draw::Window(1, 1, 9, 6, "Hold");
    // 游戏状态面板
    Draw::Window(7, 1, 9, 16, "Statu");

    // 游戏主窗口
    Draw::Window(1, 10, 12, 22, "Tetris");

    // 接下来的方块
    Draw::Window(1, 22, 8, 18, "Next");
    // 信息面板
    Draw::Window(19, 22, 8, 4, "Info");
}

void Loop()
{
    int x = 10;
    int y = 5;
    while (true)
    {
        // std::cout << std::format("FPS:{}", Utils::FPS());
        TerminalControl::MoveTo(y, x);
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
    TerminalControl::ShowCursor();
}

int main()
{
    Init();
    Loop();
    Exit();
}
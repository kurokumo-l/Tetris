#include "Terminal.h"
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main()
{
    int x = 5;
    int y = 10;
    TerminalControl::HideCursor();
    while (y < 30)
    {
        TerminalControl::MoveTo(y, x);
        TerminalControl::SetBackCorlor(214);
        std::cout << "  ";
        TerminalControl::ResetCorlor();
        std::this_thread::sleep_for(1s);
        TerminalControl::CleanScreen();
        y++;
    }
    TerminalControl::ShowCursor();
}
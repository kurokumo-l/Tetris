#include "Terminal.h"
#include <iostream>


constexpr std::string CSI = "\e[";

void TerminalControl::MoveTo(int row, int col)
{
    std::cout << CSI << std::format("{};{}H", row, col);
}

void TerminalControl::SetForeCorlor(int id)
{
    std::cout << CSI << std::format("38;5;{}m", id);
}

void TerminalControl::SetBackCorlor(int id)
{
    std::cout << CSI << std::format("48;5;{}m", id);
}

void TerminalControl::CleanScreen()
{
    std::cout << CSI << "2J";
}

void TerminalControl::ResetCorlor()
{
    std::cout << CSI << "0m";
}

void TerminalControl::HideCursor()
{
    std::cout << CSI << "?25l";
}

void TerminalControl::ShowCursor()
{
    std::cout << CSI << "?25h";
}
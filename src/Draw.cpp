#include "Draw.h"
#include "Terminal.h"
#include <iostream>
#include <string>

int Draw::ColCast(int col)
{
    return col * 2 - 1;
}

void Draw::Window(int top, int left, int width, int height, std::string title)
{
    // 第一行
    TerminalControl::MoveTo(top, ColCast(left));
    std::cout << " ┌";
    for (int i = 1; i < width - 1; i++)
    {
        std::cout << "──";
    }
    std::cout << "┐ ";

    // 第二行到倒数第二行
    for (int i = 1; i < height - 1; i++)
    {
        TerminalControl::MoveTo(top + i, ColCast(left));
        std::cout << " │";
        for (int j = 1; j < width - 1; j++)
        {
            std::cout << "  ";
        }
        std::cout << "│ ";
    }

    // 最后一行
    TerminalControl::MoveTo(top + height - 1, ColCast(left));
    std::cout << " └";
    for (int i = 1; i < width - 1; i++)
    {
        std::cout << "──";
    }
    std::cout << "┘ ";

    // 标题
    TerminalControl::MoveTo(top, ColCast((width - (int)title.length()) / 2 + left + 1));
    std::cout << title;
}
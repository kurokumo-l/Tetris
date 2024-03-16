#ifndef _TERMINAL_H_
#define _TERMINAL_H_

#include <string>

namespace TerminalControl
{

constexpr std::string CSI = "\e[";

void MoveTo(int row, int col);
void SetForeCorlor(int id);
void SetBackCorlor(int id);
void ResetCorlor();
void CleanScreen();
void HideCursor();
void ShowCursor();
} // namespace TerminalControl

#endif
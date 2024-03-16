#ifndef _DRAW_H_
#define _DRAW_H_

#include <string>
namespace Draw
{
int ColCast(int col);
void Window(int top, int left, int width, int height, const std::string &title);
} // namespace Draw

#endif
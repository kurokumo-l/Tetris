#include "Utils.h"
#include <chrono>
#include <Windows.h>
#include <winuser.h>

int Utils::FPS()
{
    using namespace std::chrono_literals;
    static int fps = 0;

    static int frameCount = 0;
    static auto startTime = std::chrono::high_resolution_clock::now();

    auto endTime = std::chrono::high_resolution_clock::now();
    frameCount++;

    if (endTime - startTime > 1s)
    {
        fps = frameCount;
        frameCount = 0;
        startTime = endTime;
    }
    return fps;
}

bool Utils::IsKeyDown(int vKey)
{
    static const int Mask = 0x8000;
    if (GetAsyncKeyState(vKey) & Mask)
    {
        return true;
    }
    return false;
}
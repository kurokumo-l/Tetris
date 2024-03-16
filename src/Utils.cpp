#include "utils.h"
#include <chrono>

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
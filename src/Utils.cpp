#include "Utils.h"
#include <Windows.h>
#include <map>
#include <stringapiset.h>
#include <utility>
#include <winnls.h>
#include <winuser.h>

namespace Utils
{
	int FPS()
	{
		using namespace std::chrono_literals;
		static int fps = 0;

		static int	frameCount = 0;
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

	bool Timer(std::chrono::microseconds duration)
	{
		static auto startTime = std::chrono::high_resolution_clock::now();

		auto endTime = std::chrono::high_resolution_clock::now();
		if (endTime - startTime > duration)
		{
			startTime = endTime;
			return true;
		}
		return false;
	}

} // namespace Utils
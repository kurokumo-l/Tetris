#ifndef _UTILS_H_
#define _UTILS_H_

#include <chrono>

namespace Utils
{
	int	 FPS();
	bool Timer(std::chrono::microseconds duration);
} // namespace Utils

#endif
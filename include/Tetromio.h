#ifndef _TERTROMINO_H
#define _TERTROMINO_H

#include "Corlor.h"
#include <vector>

namespace Game
{
	using Tetromino = std::vector<std::vector<int>>;

	extern const Tetromino I;
	extern const Tetromino J;
	extern const Tetromino L;
	extern const Tetromino O;
	extern const Tetromino S;
	extern const Tetromino T;
	extern const Tetromino Z;

    constexpr int ICorlor = (int)Corlor::Cyan;
    constexpr int JCorlor = (int)Corlor::Blue;
    constexpr int LCorlor = (int)Corlor::Orange;
    constexpr int OCorlor = (int)Corlor::Yellow;
    constexpr int SCorlor = (int)Corlor::Green;
    constexpr int TCorlor = (int)Corlor::Purple;
    constexpr int ZCorlor = (int)Corlor::Red;
	Tetromino RotateTetromino(const Tetromino& t);
} // namespace Game

#endif
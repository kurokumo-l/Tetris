#ifndef _TERTROMINO_H
#define _TERTROMINO_H

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

	Tetromino RotateTetromino(Tetromino t);
} // namespace Game

#endif
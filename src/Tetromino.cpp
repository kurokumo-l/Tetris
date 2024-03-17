#include "Tetromio.h"

const Game::Tetromino I{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 1 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
};
const Game::Tetromino J{
	{ 1, 0, 0 },
	{ 1, 1, 1 },
	{ 0, 0, 0 },
};
const Game::Tetromino L{
	{ 0, 0, 1 },
	{ 1, 1, 1 },
	{ 0, 0, 0 },
};
const Game::Tetromino O{
	{ 0, 1, 1 },
	{ 0, 1, 1 },
	{ 0, 0, 0 },
};
const Game::Tetromino S{
	{ 0, 1, 1 },
	{ 1, 1, 0 },
	{ 0, 0, 0 },
};
const Game::Tetromino T{
	{ 0, 1, 0 },
	{ 1, 1, 1 },
	{ 0, 0, 0 },
};
const Game::Tetromino Z{
	{ 1, 1, 0 },
	{ 0, 1, 1 },
	{ 0, 0, 0 },
};

Game::Tetromino Game::RotateTetromino(Game::Tetromino t)
{
	Tetromino result = std::move(t);

	// 点的旋转，向右90°
	int offset = (int)t.size() / 2;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			result[j][2 * offset - j] = t[i][j];
		}
	}

	return result;
};
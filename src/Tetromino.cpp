#include "Tetromio.h"

const Game::Tetromino Game::I{
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, ICorlor, ICorlor, ICorlor, ICorlor },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
};
const Game::Tetromino Game::J{
	{ JCorlor, 0, 0 },
	{ JCorlor, JCorlor, JCorlor },
	{ 0, 0, 0 },
};
const Game::Tetromino Game::L{
	{ 0, 0, LCorlor },
	{ LCorlor, LCorlor, LCorlor },
	{ 0, 0, 0 },
};
const Game::Tetromino Game::O{
	{ 0, OCorlor, OCorlor },
	{ 0, OCorlor, OCorlor },
	{ 0, 0, 0 },
};
const Game::Tetromino Game::S{
	{ 0, SCorlor, SCorlor },
	{ SCorlor, SCorlor, 0 },
	{ 0, 0, 0 },
};
const Game::Tetromino Game::T{
	{ 0, TCorlor, 0 },
	{ TCorlor, TCorlor, TCorlor },
	{ 0, 0, 0 },
};
const Game::Tetromino Game::Z{
	{ ZCorlor, ZCorlor, 0 },
	{ 0, ZCorlor, ZCorlor },
	{ 0, 0, 0 },
};

Game::Tetromino Game::RotateTetromino(const Game::Tetromino& t)
{
	Tetromino result = t;

	// 点的旋转，向右90°
	int offset = (int)t.size() / 2;
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
		{
			result[j][2 * offset - i] = t[i][j];
		}
	}

	return result;
};
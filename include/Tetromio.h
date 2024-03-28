#ifndef _TERTROMINO_H
#define _TERTROMINO_H

#include "Corlor.h"
#include <array>
#include <utility>
#include <vector>

namespace Game
{
	using TetrominoSet = std::array<std::array<std::pair<int, int>, 4>, 4>;
	using Offset = std::vector<std::vector<std::pair<int, int>>>;

	// Tetromino
	constexpr TetrominoSet I = { {
		{ { { 'I', Corlor::Cyan }, { -1, 0 }, { 1, 0 }, { 2, 0 } } },
		{ { { 'I', Corlor::Cyan }, { 0, 1 }, { 0, -1 }, { 0, -2 } } },
		{ { { 'I', Corlor::Cyan }, { -2, 0 }, { -1, 0 }, { 1, 0 } } },
		{ { { 'I', Corlor::Cyan }, { 0, -1 }, { 0, 1 }, { 0, 2 } } },
	} };
	constexpr TetrominoSet J = { {
		{ { { 'J', Corlor::Blue }, { -1, 1 }, { -1, 0 }, { 1, 0 } } },
		{ { { 'J', Corlor::Blue }, { 1, 1 }, { 0, 1 }, { 0, -1 } } },
		{ { { 'J', Corlor::Blue }, { -1, 0 }, { 1, 0 }, { 1, -1 } } },
		{ { { 'J', Corlor::Blue }, { 0, 1 }, { -1, -1 }, { 0, -1 } } },
	} };
	constexpr TetrominoSet L = { {
		{ { { 'L', Corlor::Orange }, { -1, 0 }, { 1, 0 }, { 1, 1 } } },
		{ { { 'L', Corlor::Orange }, { 0, 1 }, { 0, -1 }, { 1, -1 } } },
		{ { { 'L', Corlor::Orange }, { -1, -1 }, { -1, 0 }, { 1, 0 } } },
		{ { { 'L', Corlor::Orange }, { -1, 1 }, { 0, 1 }, { 0, -1 } } },
	} };
	constexpr TetrominoSet O = { {
		{ { { 'O', Corlor::Yellow }, { 0, 1 }, { 1, 0 }, { 1, 1 } } },
		{ { { 'O', Corlor::Yellow }, { 1, 0 }, { 0, -1 }, { 1, -1 } } },
		{ { { 'O', Corlor::Yellow }, { -1, -1 }, { -1, 0 }, { 0, -1 } } },
		{ { { 'O', Corlor::Yellow }, { -1, 1 }, { 0, 1 }, { -1, 0 } } },
	} };
	constexpr TetrominoSet S = { {
		{ { { 'S', Corlor::Green }, { -1, 0 }, { 0, 1 }, { 1, 1 } } },
		{ { { 'S', Corlor::Green }, { 0, 1 }, { 1, 0 }, { 1, -1 } } },
		{ { { 'S', Corlor::Green }, { -1, -1 }, { 1, 0 }, { 0, -1 } } },
		{ { { 'S', Corlor::Green }, { -1, 1 }, { -1, 0 }, { 0, -1 } } },
	} };
	constexpr TetrominoSet T = { {
		{ { { 'T', Corlor::Purple }, { -1, 0 }, { 0, 1 }, { 1, 0 } } },
		{ { { 'T', Corlor::Purple }, { 0, 1 }, { 1, 0 }, { 0, -1 } } },
		{ { { 'T', Corlor::Purple }, { -1, 0 }, { 1, 0 }, { 0, -1 } } },
		{ { { 'T', Corlor::Purple }, { -1, 0 }, { 0, 1 }, { 0, -1 } } },
	} };
	constexpr TetrominoSet Z = { {
		{ { { 'Z', Corlor::Red }, { -1, 1 }, { 0, 1 }, { 1, 0 } } },
		{ { { 'Z', Corlor::Red }, { 1, 1 }, { 1, 0 }, { 0, -1 } } },
		{ { { 'Z', Corlor::Red }, { -1, 0 }, { 0, -1 }, { 1, -1 } } },
		{ { { 'Z', Corlor::Red }, { -1, -1 }, { -1, 0 }, { 0, 1 } } },
	} };

	// Offset
	const Offset Offset_Normal = { {
		{ { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } } },
		{ { { 0, 0 }, { 1, 0 }, { 1, -1 }, { 0, 2 }, { 1, 2 } } },
		{ { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } } },
		{ { { 0, 0 }, { -1, 0 }, { -1, -1 }, { 0, 2 }, { -1, 2 } } },
	} };

	const Offset Offset_I = { {
		{ { { 0, 0 }, { -1, 0 }, { 2, 0 }, { -1, 0 }, { 2, 0 } } },
		{ { { -1, 0 }, { 0, 0 }, { 0, 0 }, { 0, 1 }, { 0, -2 } } },
		{ { { -1, 1 }, { 1, 1 }, { -2, 1 }, { 1, 0 }, { -2, 0 } } },
		{ { { 0, 1 }, { 0, 1 }, { 0, 1 }, { 0, -1 }, { 0, 2 } } },
	} };

	const Offset Offset_O = { {
		{ { { 0, 0 } } },
		{ { { 0, -1 } } },
		{ { { -1, -1 } } },
		{ { { -1, 0 } } },
	} };

} // namespace Game

#endif
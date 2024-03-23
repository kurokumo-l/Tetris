#include "Game.h"
#include "Board.h"
#include "Control.h"
#include "Piece.h"
#include "Tetromio.h"
#include "Utils.h"
#include <chrono>
#include <cstdlib>
#include <ranges>
#include <vector>

namespace Game
{
	bool					  isRunning;
	Board					  playfield;
	Board					  frame;
	Piece					  onePiece;
	bool					  isPrepareToLock;
	std::chrono::microseconds duration;

	void Init()
	{
		using namespace std::chrono;

		isRunning = true;
		// mino = playfield[y][x]
		playfield = std::vector<std::vector<int>>(RowNum, std::vector<int>(ColNum, 0));
		onePiece = Pick();
		frame = playfield;
		isPrepareToLock = false;
		duration = 500ms;
	}

	void Process()
	{
		HandleInput();
		if (Utils::Timer(duration))
		{
			if (onePiece.MoveDown())
			{
				return;
			}
			if (!isPrepareToLock)
			{
				isPrepareToLock = true;
				return;
			}
			isPrepareToLock = false;
			Lock();
			Clear();
			onePiece = Pick();
		}
	}

	void Render()
	{
		frame = playfield;
		auto [ox, oy] = onePiece.GetPosition();

		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = onePiece.GetMino(i);
			int x = ox + dx;
			int y = oy + dy;
			frame[y][x] = onePiece.GetColor();
		}
		while (onePiece.Test({ ox, --oy }))
			;
		oy++;
		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = onePiece.GetMino(i);
			int x = ox + dx;
			int y = oy + dy;
			frame[y][x] = -onePiece.GetColor();
		}
	}

	Piece Pick()
	{
		static std::vector<TetrominoSet> bag{ I, J, L, O, S, T, Z };
		return { bag[rand() % 7], 0, { 4, 20 }, &playfield };
	}

	void Lock()
	{
		auto [ox, oy] = onePiece.GetPosition();

		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = onePiece.GetMino(i);
			int x = ox + dx;
			int y = oy + dy;
			playfield[y][x] = onePiece.GetColor();
		}
	}

	void Clear()
	{
		for (auto it = playfield.begin(); it != playfield.end(); it++)
		{
			bool isFull = true;
			for (auto mino : *it)
			{
				if (mino == 0)
				{
					isFull = false;
					break;
				}
			}
			if (isFull)
			{
				it = playfield.erase(it);
				playfield.emplace_back(it->size(), 0);
                it--;
			}
		}
	}

	void Quit()
	{
		isRunning = false;
	}

	void Rotate()
	{
		onePiece.Rotate();
	}
	void MoveDown()
	{
		onePiece.MoveDown();
	}
	void MoveLeft()
	{
		onePiece.MoveLeft();
	}
	void MoveRight()
	{
		onePiece.MoveRight();
	}
	void Drop()
	{
		while (onePiece.MoveDown())
			;
		isPrepareToLock = true;
	}
} // namespace Game
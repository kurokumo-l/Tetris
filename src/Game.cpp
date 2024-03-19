#include "Game.h"
#include "Board.h"
#include "Control.h"
#include "Piece.h"
#include "Tetromio.h"
#include "Utils.h"
#include <chrono>
#include <ranges>
#include <vector>

namespace Game
{
	bool					  isRunning;
	Board					  board;
	Board					  frame;
	Piece					  onePiece;
	std::chrono::microseconds duration;

	void Init()
	{
		using namespace std::chrono;

		isRunning = true;
		board = std::vector<std::vector<int>>(ColNum, std::vector<int>(RowNum, 0));
		onePiece = Pick();
		frame = board;
		duration = 500ms;
	}

	void Process()
	{
		HandleInput();
		if (Utils::Timer(duration))
		{
			onePiece.MoveDown();
		}
        Render();
	}

	void Render()
	{
		frame = board;
		auto [ox, oy] = onePiece.GetPosition();

		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = onePiece.GetMino(i);
			frame[ox + dx][oy + dy] = onePiece.GetColor();
		}
		while (onePiece.Test({ ox, --oy }))
			;
		oy++;
		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = onePiece.GetMino(i);
			frame[ox + dx][oy + dy] = -onePiece.GetColor();
		}
	}

	void Quit()
	{
		isRunning = false;
	}

	Piece Pick()
	{
		// TODO:  返回待选列表中的一个棋子
		return {Game::I, 0, {4, 20}, &board};
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
} // namespace Game
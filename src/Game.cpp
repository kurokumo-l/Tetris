#include "Game.h"
#include "Board.h"
#include "Control.h"
#include "Piece.h"
#include "Tetromio.h"
#include "Utils.h"
#include <chrono>
#include <cstdlib>
#include <queue>
#include <ranges>
#include <vector>

namespace Game
{
	bool					  isRunning;
	Board					  playfield;
	Board					  frame;
	Piece					  onePiece;
	std::queue<TetrominoSet>  previewQuene;
	bool					  isPrepareToLock;
	std::chrono::microseconds duration;

	void Init()
	{
		using namespace std::chrono;

		isRunning = true;
		// mino = playfield[y][x]
		playfield = std::vector<std::vector<int>>(RowNum, std::vector<int>(ColNum, 0));
		GetPreview();
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
		PlacePiece(frame, onePiece);

		Piece shadow = onePiece;
		shadow.SetIsShadow(true);
		while (shadow.MoveDown())
			;

		PlacePiece(frame, shadow);
	}

	Piece Pick()
	{
		Piece res = { previewQuene.front(), 0, { 4, 20 }, &playfield };
		previewQuene.pop();
		GetPreview();
		return res;
	}

	void GetPreview()
	{
		static std::vector<TetrominoSet> bag{ I, J, L, O, S, T, Z };
		static std::vector<TetrominoSet> currentBag{ bag };
		while (previewQuene.size() < 5)
		{
			int index = (int)(rand() % currentBag.size());
			previewQuene.push(currentBag[index]);
			currentBag.erase(currentBag.begin() + index);
			if (currentBag.empty())
			{
				currentBag = bag;
			}
		}
	}

	void Lock()
	{
		PlacePiece(playfield, onePiece);
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

	void PlacePiece(Board& board, const Piece& piece)
	{
		auto [ox, oy] = piece.GetPosition();

		for (auto i : std::ranges::views::iota(0, 4))
		{
			auto [dx, dy] = piece.GetMino(i);
			int x = ox + dx;
			int y = oy + dy;
			board[y][x] = piece.GetColor();
		}
	}
} // namespace Game
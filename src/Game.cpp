#include "Game.h"
#include "Board.h"
#include "Control.h"
#include "Corlor.h"
#include "Piece.h"
#include "Tetromio.h"
#include "Utils.h"
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <ranges>
#include <vector>

namespace Game
{
	bool					  isRunning;
	Board					  playfield;
	Board					  frame;
	Piece					  onePiece;
	std::queue<TetrominoSet>  holdQuene;
	std::queue<TetrominoSet>  previewQuene;
	bool					  isEnd;
	bool					  isHolding;
	bool					  isPrepareToLock;
	std::chrono::microseconds duration;
	int						  score;
	int						  level;
	int						  lines;

	void Init()
	{
		using namespace std::chrono;

		isRunning = true;
        isEnd =false;

		// mino = playfield[y][x]
		playfield = std::vector<std::vector<int>>(RowNum, std::vector<int>(ColNum, 0));
		// std::fstream map {"resource/map.txt"};
		// LoadMap(map);

		GetPreview();
		onePiece = Pick();

		frame = playfield;

		isPrepareToLock = false;

		score = 0;
		lines = 1;
		LevelUp();
	}

	void Process()
	{
		if (isEnd)
		{
			return;
        }
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
			isHolding = false;
			Lock();
			Clear();
			LevelUp();
			onePiece = Pick();
			if (!onePiece.Test({4, 20}))
			{
                isEnd = true;
            }
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

	void HoldPiece()
	{
		if (isHolding)
		{
			return;
		}
		if (holdQuene.empty())
		{
			holdQuene.push(onePiece.GetTetromino());
			onePiece = Pick();
		}
		else
		{
			TetrominoSet temp = holdQuene.front();
			holdQuene.pop();
			holdQuene.push(onePiece.GetTetromino());
			onePiece = { temp, 0, { 4, 20 }, &playfield };
		}
		isHolding = true;
	}

	void Lock()
	{
		PlacePiece(playfield, onePiece);
	}

	void Clear()
	{
		int count = 0;
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
				count++;
			}
		}
		lines += count;
		score += (int)pow(2, count - 1) * 100 * level;
	}

	void Quit()
	{
		isRunning = false;
	}

	void LevelUp()
	{
		level = lines / 10 + 1;
		duration = std::chrono::milliseconds((int)pow((0.8) - (level - 1) * 0.007, level - 1) * 1000);
	}

	void LoadMap(std::fstream& file)
	{
		for (auto& row : playfield | std::ranges::views::take(20) | std::ranges::views::reverse)
		{
			for (auto i : std::ranges::views::iota(0, 10))
			{
				char mino = 0;
				file >> mino;
				if (mino == '1')
				{
					row[i] = Corlor::Gray;
				}
			}
		}
	}

	void RotateL()
	{
		onePiece.Rotate(3);
	}
	void RotateR()
	{
		onePiece.Rotate(1);
	}
	void RotateRD()
	{
		onePiece.Rotate(2);
	}

	void MoveDown()
	{
		if (onePiece.MoveDown())
		{
			score += 1;
		}
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
		score += 2;
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
			if (board[y][x] == 0)
				board[y][x] = piece.GetColor();
		}
	}
} // namespace Game
#ifndef _PIECE_H_
#define _PIECE_H_

#include "Board.h"
#include "Tetromio.h"
#include <utility>
namespace Game
{
	class Piece
	{
	public:
		Piece();
		Piece(TetrominoSet ts, int index, std::pair<int, int> position, Board* board);

		[[nodiscard]] std::pair<int, int> GetPosition() const;
		[[nodiscard]] std::pair<int, int> GetMino(int i) const;
		[[nodiscard]] int				  GetColor() const;
		[[nodiscard]] bool				  Test(std::pair<int, int> position) const;

		bool Rotate();
		bool MoveDown();
		bool MoveLeft();
		bool MoveRight();

	private:
		bool MoveTo(std::pair<int, int> newPostion);

		TetrominoSet		m_TetrominoSet;
		int					m_Index;
		std::pair<int, int> m_Position;
		Board*				m_Board;

	}; // namespace Game
} // namespace Game
#endif
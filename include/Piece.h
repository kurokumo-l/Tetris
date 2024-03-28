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
		Piece() = default;
		Piece(TetrominoSet ts, int index, std::pair<int, int> position, Board* board);

		[[nodiscard]] std::pair<int, int> GetPosition() const;
		[[nodiscard]] std::pair<int, int> GetMino(int i) const;
		[[nodiscard]] int				  GetColor() const;
		[[nodiscard]] int				  GetType() const;
		[[nodiscard]] TetrominoSet		  GetTetromino() const;
		[[nodiscard]] bool				  Test(std::pair<int, int> position) const;

		bool Rotate(int count);
		bool MoveDown();
		bool MoveLeft();
		bool MoveRight();
		void SetIsShadow(bool isShadow);

	private:
		bool MoveTo(std::pair<int, int> newPostion);

		TetrominoSet		m_TetrominoSet;
		Offset				m_Offset;
		int					m_Index;
		std::pair<int, int> m_Position;
		Board*				m_Board;
		bool				m_IsShadow;

	}; // namespace Game
} // namespace Game
#endif
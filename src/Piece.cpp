#include "Piece.h"
#include "Board.h"
#include "Tetromio.h"
#include <ranges>
#include <utility>

namespace Game
{
	Piece::Piece(TetrominoSet ts, int index, std::pair<int, int> position, Board* board)
		: m_TetrominoSet(std::move(ts)), m_Offset(Offset_Normal), m_Index(index), m_Position(position), m_Board(board), m_IsShadow(false)
	{
		if (GetType() == 'I')
		{
			m_Offset = Offset_I;
		}
		else if (GetType() == 'O')
		{
			m_Offset = Offset_O;
		}
	}

	bool Piece::Test(std::pair<int, int> position) const
	{
		int ox = position.first;
		int oy = position.second;
		for (int i = 0; i < 4; i++)
		{
			auto [dx, dy] = GetMino(i);
			int x = ox + dx;
			int y = oy + dy;
			if (x < 0 || x >= m_Board->front().size() || y < 0 || y >= m_Board->size())
			{
				return false;
			}
			if ((*m_Board)[y][x] > 0)
			{
				return false;
			}
		}
		return true;
	}

	std::pair<int, int> Piece::GetMino(int i) const
	{
		if (i == 0)
		{
			return { 0, 0 };
		}
		return m_TetrominoSet[m_Index][i];
	}

	std::pair<int, int> Piece::GetPosition() const
	{
		return m_Position;
	}

	int Piece::GetColor() const
	{
		int flag = m_IsShadow ? -1 : 1;
		return flag * m_TetrominoSet[0][0].second;
	}

	int Piece::GetType() const
	{
		return m_TetrominoSet[0][0].first;
	}

	TetrominoSet Piece::GetTetromino() const
	{
		return m_TetrominoSet;
	}

	bool Piece::Rotate(int count)
	{
		int beforeIndex = m_Index;
		m_Index = (m_Index + count) % 4;
		for (auto i : std::ranges::views::iota(0, (int)m_Offset[0].size()))
		{
			auto [dx0, dy0] = m_Offset[beforeIndex][i];
			auto [dx1, dy1] = m_Offset[m_Index][i];
			auto x = m_Position.first + dx0 - dx1;
			auto y = m_Position.second + dy0 - dy1;
			if (MoveTo({ x, y }))
			{
				return true;
			}
		}
		m_Index = beforeIndex;
		return false;
		if (!Test(m_Position))
		{
			m_Index = (m_Index + 3) % 4;
			return false;
		}
		return true;
	}
	bool Piece::MoveDown()
	{
		return MoveTo({ m_Position.first, m_Position.second - 1 });
	}

	bool Piece::MoveLeft()
	{
		return MoveTo({ m_Position.first - 1, m_Position.second });
	}

	bool Piece::MoveRight()
	{
		return MoveTo({ m_Position.first + 1, m_Position.second });
	}

	bool Piece::MoveTo(std::pair<int, int> newPostion)
	{
		if (Test(newPostion))
		{
			m_Position = newPostion;
			return true;
		}
		return false;
	}
	void Piece::SetIsShadow(bool isShadow)
	{
		m_IsShadow = isShadow;
	}
} // namespace Game
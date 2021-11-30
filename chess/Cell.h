#ifndef CHESS_CELL_H_
#define CHESS_CELL_H_

#include <tuple>

struct Cell {
	int32_t col;
	int32_t row;
	bool isEmpty = false;

	bool operator < (const Cell& other)
	{
	   return std::tie(col, row) < std::tie(other.col, other.row);
	}
};

#endif

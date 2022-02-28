#ifndef CHESS_GAME_BOARD_CELL_H_
#define CHESS_GAME_BOARD_CELL_H_

#include <cstdint>
#include <iostream>

struct Cell {
	Cell(int32_t row, int32_t col);

	int32_t row;
	int32_t col;

	bool operator==(const Cell& cell) const;
	bool operator!=(const Cell& cell) const;

	Cell& moveTop();
	Cell& moveRight();
	Cell& moveDown();
	Cell& moveLeft();

	struct HashFunction {
		size_t operator()(const Cell& cell) const {
			size_t rowHash = std::hash<int32_t>()(cell.row);
			size_t colHash = std::hash<int32_t>()(cell.col) << 16;

			return rowHash ^ colHash;
		}
	};

	static const Cell UNDEFINED;

	friend std::ostream& operator<<(std::ostream& os, const Cell& cell);

};


#endif /* CHESS_GAME_BOARD_CELL_H_ */

/*
 * Cell.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_BOARD_CELL_H_
#define CHESS_GAME_BOARD_CELL_H_

#include <cstdint>

struct Cell {
	Cell(int32_t row, int32_t col);

	int32_t row;
	int32_t col;

	bool operator==(const Cell& cell) const;
	bool operator!=(const Cell& cell) const;

	static const Cell UNDEFINED;
};


#endif /* CHESS_GAME_BOARD_CELL_H_ */

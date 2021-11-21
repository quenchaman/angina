/*
 * Piece.h
 *
 *  Created on: Nov 19, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_PIECE_H_
#define CHESS_PIECE_H_

#include <cstdint>

#include "Side.h"
#include "Rank.h"

class Piece {
public:
	static const int32_t PIECE_WIDTH = 80;
	static const int32_t PIECE_HEIGHT = 80;

	Piece(int32_t id, int32_t col, int32_t row, Rank rank, Side side);

	int32_t getCol();

	int32_t getRow();

	Rank getRank();

	Side getSide();

private:
	int32_t id;
	int32_t col;
	int32_t row;
	Rank rank;
	Side side;
};


#endif /* CHESS_PIECE_H_ */

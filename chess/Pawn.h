/*
 * PAWN.h
 *
 *  Created on: Nov 24, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_PAWN_H_
#define CHESS_PAWN_H_

#include <vector>
#include <cstdint>

#include "Side.h"

#include "Cell.h"
#include "sdl/graphics/Texture.h"
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int32_t col, int32_t row, Side side, Image* image);
    ~Pawn();

	std::vector<Cell> calculateMoves(std::vector<Piece*> boardPieces);
};

#endif /* CHESS_PAWN_H_ */

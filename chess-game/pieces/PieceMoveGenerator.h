/*
 * PieceMoveGenerator.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_
#define CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_

#include <vector>

#include "chess-game/pieces/Move.h"
#include "chess-game/board/Cell.h"

class PieceMoveGenerator {
public:
	static std::vector<Move> generateKnightMoves(Cell knightPosition);
};

#endif /* CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_ */

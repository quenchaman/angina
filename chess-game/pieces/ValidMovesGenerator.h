/*
 * ValidMovesGenerator.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_
#define CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_

#include <vector>

#include "chess-game/pieces/Move.h"

struct Board;
struct Piece;

class ValidMovesGenerator {
public:
	ValidMovesGenerator(Board& board);

	std::vector<Move> generateValidMoves(Piece* piece);
private:
	Board& _board;

	std::vector<Move> filterInvalidMoves(std::vector<Move> moves);
};

#endif /* CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_ */

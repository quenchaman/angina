/*
 * PieceValue.h
 *
 *  Created on: Jan 27, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PIECES_PIECEVALUE_H_
#define CHESS_GAME_PIECES_PIECEVALUE_H_

#include <unordered_map>

#include "chess-game/pieces/Rank.h"

namespace PieceValue {
	static std::unordered_map<Rank, double> pieceValues = {
			{Rank::PAWN, 1},
			{Rank::KNIGHT, 3},
			{Rank::BISHOP, 3},
			{Rank::ROOK, 5},
			{Rank::QUEEN, 9},
			{Rank::KING, 1000}
	};

	static double getPieceValue(Rank r) {
		return pieceValues[r];
	}
}


#endif /* CHESS_GAME_PIECES_PIECEVALUE_H_ */

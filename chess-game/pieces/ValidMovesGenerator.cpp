/*
 * ValidMovesGenerator.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#include "ValidMovesGenerator.h"

#include "chess-game/pieces/Piece.h"
#include "chess-game/board/Board.h"
#include "chess-game/pieces/PieceMoveGenerator.h"

ValidMovesGenerator::ValidMovesGenerator(Board& board): _board(board) {
}

std::vector<Move> ValidMovesGenerator::generateValidMoves(Piece* piece) {
	std::vector<Move> moves;

	switch (piece->rank) {
		case Rank::KNIGHT:
			moves = PieceMoveGenerator::generateKnightMoves(piece->cell);
			break;
		default:
			break;
	}

	std::vector<Move> validMoves;

	for (auto& move : moves) {
		// TODO: check if this is a white piece. If it is then it is not a valid move.
		if (_board.isBoardPosition(move.dst)) {

		}
	}
}

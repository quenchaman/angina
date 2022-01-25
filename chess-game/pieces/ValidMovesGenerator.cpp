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
	Side enemySide = piece->side == Side::Black ? Side::White : Side::Black;

	switch (piece->rank) {
		case Rank::KNIGHT:
			moves = filterInvalidMoves(PieceMoveGenerator::generateKnightMoves(piece->cell), enemySide);
			break;
		default:
			break;
	}

	return filterInvalidMoves(moves, enemySide);
}

std::vector<Move> ValidMovesGenerator::filterInvalidMoves(std::vector<Move> moves, Side enemySide) {
	std::vector<Move> validMoves;

	for (auto& move : moves) {
		bool isPositionInBoard = _board.isBoardPosition(move.dst);
		bool isEmptyCellOrEnemyCell = _board.isEmptyCell(move.dst) || _board.isSidePieceSelected(move.dst, enemySide);

		if (isPositionInBoard && isEmptyCellOrEnemyCell) {
			validMoves.push_back(move);
		}
	}

	return validMoves;
}

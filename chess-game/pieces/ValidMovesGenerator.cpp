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
			moves = filterInvalidMoves(PieceMoveGenerator::generateKnightMoves(piece->cell));
			break;
		default:
			break;
	}

	return filterInvalidMoves(moves);
}

std::vector<Move> ValidMovesGenerator::filterInvalidMoves(std::vector<Move> moves) {
	std::vector<Move> validMoves;

	for (auto& move : moves) {
		bool isPositionInBoard = _board.isBoardPosition(move.dst);
		bool isEmptyCellOrEnemyCell = _board.isEmptyCell(move.dst) || _board.isSidePieceSelected(move.dst, Side::Black);
		std::cout << "Candidate move " << move << " Is empty cell " << _board.isEmptyCell(move.dst) << std::endl;
		if (isPositionInBoard && isEmptyCellOrEnemyCell) {
			std::cout << "Entering move " << move << std::endl;
			validMoves.push_back(move);
		}
	}

	return validMoves;
}

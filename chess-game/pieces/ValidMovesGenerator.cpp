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

	return filterInvalidMoves(moves);
}

std::vector<Move> ValidMovesGenerator::filterInvalidMoves(std::vector<Move> moves) {
	std::vector<Move> validMoves;

	for (auto& move : moves) {
		if (_board.isBoardPosition(move.dst) && (_board.isEmptyCell(move.dst) || _board.getPieceOnPosition(move.dst)->side == Side::Black)) {
			std::cout << "Do we get until here?" << std::endl;
			bool isEmpty = _board.isEmptyCell(move.dst);
			bool isBlack = _board.getPieceOnPosition(move.dst)->side == Side::Black;
			std::cout << "destination: " << move.dst << " source: " << move.src << " empty: " << isEmpty << " black: " << isBlack << std::endl;
			validMoves.push_back(move);
		}
	}

	return validMoves;
}

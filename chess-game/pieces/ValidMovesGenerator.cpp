#include "ValidMovesGenerator.h"

#include "chess-game/board/Board.h"
#include "chess-game/pieces/PieceMoveGenerator.h"
#include "PieceObject.h"

ValidMovesGenerator::ValidMovesGenerator(Board& board): _board(board) {
}

std::vector<Move> ValidMovesGenerator::generatePieceMoves(Piece piece) const {
	std::vector<Move> moves;

	switch (piece.rank) {
		case Rank::KNIGHT:
			moves = filterInvalidMoves(PieceMoveGenerator::generateKnightMoves(piece->cell), enemySide);
			break;
		default:
			break;
	}

	return filterInvalidMoves(moves, enemySide);
}

std::vector<Move> ValidMovesGenerator::generatePieceMoves(Piece piece) const {
	std::vector<Move> moves;

	switch (piece.rank) {
		case Rank::KNIGHT:
			moves = filterInvalidMoves(PieceMoveGenerator::generateKnightMoves(piece->cell), enemySide);
			break;
		default:
			break;
	}

	return filterInvalidMoves(moves, enemySide);
}

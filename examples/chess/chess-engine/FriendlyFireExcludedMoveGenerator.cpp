#include "FriendlyFireExcludedMoveGenerator.h"

#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/BoundsMoveGenerator.h"

FriendlyFireExcludedMoveGenerator::FriendlyFireExcludedMoveGenerator(
		ChessBoard& chessBoard,
		BoundsMoveGenerator& generator): board(chessBoard), moveGen(generator) {}

CellUnorderedSet FriendlyFireExcludedMoveGenerator::generatePieceMoves(const Cell& pieceCell) const {
	CellUnorderedSet friendlyFireExcludedMoves;

	if (board.isEmptyCell(pieceCell)) {
		return friendlyFireExcludedMoves;
	}

	Piece piece = board.getPieceOnCell(pieceCell);

	CellUnorderedSet boundedMoves = moveGen.generatePieceMoves(piece, pieceCell);

	for (auto const& cell : boundedMoves) {
		if (board.isEmptyCell(cell) || board.getPieceOnCell(cell).side != piece.side) {
			friendlyFireExcludedMoves.insert(cell);
		}
	}

	return friendlyFireExcludedMoves;
}

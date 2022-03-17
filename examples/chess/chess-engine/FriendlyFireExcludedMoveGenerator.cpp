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

	std::cout << "Are we at least here?" << std::endl;

	CellUnorderedSet boundedMoves = moveGen.generatePieceMoves(piece, pieceCell);

	std::cout << "Bounded moves are with size: " << boundedMoves.size() << std::endl;

	for (auto const& cell : boundedMoves) {
		friendlyFireExcludedMoves.insert(cell);
	}

	return friendlyFireExcludedMoves;
}

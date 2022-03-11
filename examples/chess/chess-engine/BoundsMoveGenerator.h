#ifndef EXAMPLES_CHESS_CHESS_ENGINE_BOUNDSMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_BOUNDSMOVEGENERATOR_H_

#include <unordered_set>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

struct ChessBoard;

/**
 * Generates piece moves that are within boards' bounds.
 */
class BoundsMoveGenerator {
public:
	BoundsMoveGenerator(ChessBoard&);

	CellUnorderedSet generatePieceMoves(const Piece& piece, const Cell& source) const;
private:
	ChessBoard& board;

	CellUnorderedSet generateKnightMoves(const Cell&) const;
	CellUnorderedSet generateRookMoves(const Cell&) const;
	CellUnorderedSet generateBishopMoves(const Cell&) const;
	CellUnorderedSet generateQueenMoves(const Cell&) const;
	CellUnorderedSet generatePawnMoves(const Cell&, const Side&) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_BOUNDSMOVEGENERATOR_H_ */

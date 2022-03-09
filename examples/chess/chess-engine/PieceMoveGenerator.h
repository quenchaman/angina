#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_

#include <unordered_set>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

struct ChessBoard;

/**
 * Methods to get the moves for a piece which are not outside the board and not over friendly piece.
 */
class PieceMoveGenerator {
public:
	PieceMoveGenerator(ChessBoard&);

	CellUnorderedSet generatePieceMoves(Piece, Cell source) const;
	CellUnorderedSet generateKnightMoves(Cell& knightPosition) const;
	CellUnorderedSet generateRookMoves(Cell& currentCell) const;
	CellUnorderedSet generateBishopMoves(Cell& currentCell) const;
	CellUnorderedSet generateQueenMoves(Cell& currentCell) const;
	CellUnorderedSet generatePawnMoves(Cell& currentCell, Side) const;

private:
	ChessBoard& board;

	bool isNotFriendlyOrIsEmpty(const Cell&) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_ */

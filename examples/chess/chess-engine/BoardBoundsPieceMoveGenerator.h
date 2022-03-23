#ifndef EXAMPLES_CHESS_CHESS_ENGINE_BOARDBOUNDSPIECEMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_BOARDBOUNDSPIECEMOVEGENERATOR_H_

#include <unordered_set>
#include <functional>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

typedef std::function<void(const Cell&, const Cell&)> MoveEventCallback;

struct ChessBoard;

/**
 * Generates piece moves that are within boards' bounds.
 */
class BoardBoundsPieceMoveGenerator {
public:
	BoardBoundsPieceMoveGenerator(ChessBoard&);

	CellUnorderedSet generatePieceMoves(const Piece& piece, const Cell& source) const;
private:
	ChessBoard& board;

	CellUnorderedSet generateKnightMoves(const Cell&) const;
	CellUnorderedSet generateRookMoves(const Cell&, Side) const;
	CellUnorderedSet generateBishopMoves(const Cell&, Side) const;
	CellUnorderedSet generateQueenMoves(const Cell&, Side) const;
	CellUnorderedSet generatePawnMoves(const Cell&, Side) const;
	CellUnorderedSet generateKingMoves(const Cell&, Side) const;

	bool isValidMove(const Cell&, Side) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_BOARDBOUNDSPIECEMOVEGENERATOR_H_ */

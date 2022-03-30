#ifndef EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_

#include "engine/primitives/cell/Cell.h"
#include "examples/chess/chess-engine/Piece.h"

struct ChessBoard;
struct BoardBoundsPieceMoveGenerator;

/**
 * Maybe this class is not needed. It could be replaced by a function.
 */
class FriendlyFireExcludedMoveGenerator {
public:
	FriendlyFireExcludedMoveGenerator(ChessBoard&,
			BoardBoundsPieceMoveGenerator&);

	/*
	 * Generates all moves that are not on a friendly occupied cell.
	 */
	CellUnorderedSet generatePieceMoves(const Cell&) const;
private:
	ChessBoard &board;
	BoardBoundsPieceMoveGenerator &moveGen;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_ */

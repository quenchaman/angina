#ifndef EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"

struct ChessBoard;
struct BoundsMoveGenerator;

class FriendlyFireExcludedMoveGenerator {
public:
	FriendlyFireExcludedMoveGenerator(ChessBoard&, BoundsMoveGenerator&);

	/*
	 * Generates all moves that are not on a friendly occupied cell.
	 */
	CellUnorderedSet generatePieceMoves(const Cell&) const;
private:
	ChessBoard& board;
	BoundsMoveGenerator& moveGen;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_FRIENDLYFIREEXCLUDEDMOVEGENERATOR_H_ */

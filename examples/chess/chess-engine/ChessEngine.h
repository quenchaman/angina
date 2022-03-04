#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

/**
 * This chess engine assumes that white pieces is human and black pieces is computer.
 */
class ChessEngine {
public:
	ChessEngine();
	~ChessEngine();

	void selectPiece(const Cell& source);
	void movePiece(const Cell& destination);
	const CellToPieceLookup& getPieces() const;
	const Cell getCellOfPiece(const Piece& piece) const;
	bool isCellSelected() const;

	void setState(ChessState newState);

private:
	ChessState state = ChessState::WHITE_PLAYER;
	ChessBoard board;
	Cell selectedCell = Cell::UNDEFINED;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */

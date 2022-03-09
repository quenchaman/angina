#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::function<void(const Cell&, const Cell&)> MoveEventCallback;

/**
 * This chess engine assumes that white pieces is human and black pieces is computer.
 */
class ChessEngine {
public:
	ChessEngine();
	~ChessEngine();

	void selectPiece(const Cell& source);
	bool movePiece(const Cell& destination);
	const CellToPieceLookup& getPieces() const;
	bool isCellSelected() const;

	/**
	 * AI API
	 */
	Move getAIMove();

	/*
	 * Pub-sub API
	 */
	void subscribe(MoveEventCallback);

private:
	ChessBoard board;
	Cell selectedCell = Cell::UNDEFINED;
	std::vector<MoveEventCallback> subscribers;

	void resetSelection();

	/*
	 * Pub-sub API
	 */
	void notify(const Cell& source, const Cell& destination) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */

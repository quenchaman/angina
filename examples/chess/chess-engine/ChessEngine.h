#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Move.h"

#include "examples/chess/chess-engine/PieceMoveGenerator.h"

typedef std::function<void(const Cell&, const Cell&)> MoveEventCallback;

/**
 * This chess engine assumes that white pieces is human and black pieces is computer.
 */
class ChessEngine {
public:
	ChessEngine();
	~ChessEngine();

	Side switchSide();
	void selectPiece(const Cell& source);
	bool movePiece(const Cell& destination);
	const CellToPieceLookup& getPieces() const;
	bool isCellSelected() const;

	/**
	 * Whether a move is valid in terms of piece movement rules and general chess rules: check, etc.
	 */
	bool isValidPieceMove(const Cell& source, const Cell& destination) const;

	std::vector<Move> generateValidPieceMoves(const Piece& piece, const Cell& cell) const;
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
	PieceMoveGenerator moveGen;
	Side currentSide = Side::WHITE;

	void resetSelection();

	/*
	 * Pub-sub API
	 */
	void notify(const Cell& source, const Cell& destination) const;

	/**
	 * AI API
	 */
	std::vector<Move> calculateAllAvailableMoves(Side side) const;

	double scoreMove(const Cell& destination) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */

#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_

#include "BoundsMoveGenerator.h"
#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::function<void(const Cell&, const Cell&)> MoveEventCallback;

struct FriendlyFireExcludedMoveGenerator;
struct ChessBoard;

/**
 * Oversees piece rules and piece movement. Inherit this class and override AI behavior.
 */
class ChessMoveManager {
public:
	ChessMoveManager(ChessBoard&, FriendlyFireExcludedMoveGenerator&);
	virtual ~ChessMoveManager() = default;

	bool movePiece(const Cell& source, const Cell& destination);
	virtual Move getAIMove(Side side);
	void subscribe(MoveEventCallback);

protected:
	virtual std::vector<Move> calculateAllAvailableMoves(Side side) const;
	virtual double scoreMove(const Cell& destination) const;
	virtual std::vector<Move> scorePieceMoves(const Piece& piece, const Cell& cell) const;

private:
	ChessBoard board;
	std::vector<MoveEventCallback> subscribers;
	FriendlyFireExcludedMoveGenerator& moveGen;

	void notify(const Cell& source, const Cell& destination) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_ */

#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_

#include <vector>

#include "BoardBoundsPieceMoveGenerator.h"
#include "examples/chess/chess-engine/ChessState.h"
#include "examples/chess/chess-engine/ChessBoard.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Move.h"

struct FriendlyFireExcludedMoveGenerator;
struct ChessBoard;

/**
 * Oversees piece rules and piece movement. Inherit this class and override AI behavior.
 */
class ChessMoveManager {
public:
    ChessMoveManager(ChessBoard&, FriendlyFireExcludedMoveGenerator&);
    virtual ~ChessMoveManager() = default;

    bool movePiece(const Cell &source, const Cell &destination, bool force =
            false);
    virtual std::vector<Move> getAIMoves(Side side);

    virtual std::vector<Move> calculateAllAvailableMoves(Side side);
protected:
    virtual double scoreMove(const Cell &destination) const;
    virtual std::vector<Move> scorePieceMoves(const Cell &cell) const;

private:
    ChessBoard &board;
    FriendlyFireExcludedMoveGenerator &moveGen;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSMOVEMANAGER_H_ */

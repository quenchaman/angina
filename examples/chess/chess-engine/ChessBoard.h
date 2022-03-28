#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_

#include <iostream>
#include <unordered_map>
#include <functional>
#include <string>

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::function<void(const Cell&, const Cell&)> MoveEventCallback;
typedef std::unordered_map<Cell, Piece, Cell::HashFunction> CellToPieceLookup;

/**
 * Holds data about the board and provides methods for checking physical bounds and collisions.
 */
class ChessBoard {
public:
    ChessBoard();

    const CellToPieceLookup& getPiecePositions();
    void movePiece(const Cell &source, const Cell &destination);
    void setInitialPieceFormation();
    const Piece& getPieceOnCell(const Cell &source) const;
    bool isInBounds(const Cell&) const;
    bool isEmptyCell(const Cell&) const;
    bool isSameSidePiece(const Cell&, Side) const;
    bool isValidTarget(const Cell&, Side) const;
    bool isEnemyCell(const Cell&, Side) const;

    /**
     * Works well for pieces that have only one instance per side - queen and king.
     * For other pieces, it will return the first encountered piece and its position.
     */
    Cell getPiecePosition(Piece);

    void subscribe(MoveEventCallback);

    void clearSubscribers();

private:
    CellToPieceLookup board;
    std::vector<MoveEventCallback> subscribers;

    void notify(const Cell &source, const Cell &destination) const;

    friend std::ostream& operator<<(std::ostream&, const ChessBoard&);
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_ */

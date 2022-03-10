#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_

#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>
#include <stack>

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::unordered_map<Cell, Piece, Cell::HashFunction> CellToPieceLookup;

/**
 * Holds data about the board and provides methods for checking physical bounds and collisions.
 */
class ChessBoard {
public:
	ChessBoard();

	const CellToPieceLookup& getPiecePositions() const;
	bool tryMakeMove(const Cell& source, const Cell& destination);
	bool isPossibleMove(const Cell& source, const Cell& destination) const;
	void setInitialPieceFormation();
	const Piece& getPieceOnCell(const Cell& source) const;
	bool isInBounds(const Cell&) const;
	bool isEmptyCell(const Cell&) const;

private:
	CellToPieceLookup board;

	void movePiece(const Cell& source, const Cell& destination);

	friend std::ostream& operator<<(std::ostream&, const ChessBoard&);
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_ */

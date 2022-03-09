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
#include "examples/chess/chess-engine/PieceMoveGenerator.h"

typedef std::unordered_map<Cell, Piece, Cell::HashFunction> CellToPieceLookup;

class ChessBoard {
public:
	ChessBoard();

	const CellToPieceLookup& getPiecePositions() const;

	bool makeMove(const Cell& source, const Cell& destination);

	/**
	 * Whether a move is valid based on physical rules:
	 * 1. On the source cell the piece is on move
	 * 2. Is source and destination are in the borders of the board
	 * 3. The source cell is not empty.
	 * 4. The destination cell is either empty or an enemy.
	 */
	bool isPossibleMove(const Cell& source, const Cell& destination) const;

	/**
	 * Whether a move is valid in terms of piece movement rules and general chess rules: check, etc.
	 */
	bool isValidPieceMove(const Cell& source, const Cell& destination) const;

	Side switchSide();

	void setInitialPieceFormation();

	const Piece& getPieceOnCell(const Cell& source) const;

	bool isInBounds(const Cell&) const;
	bool isEmptyCell(const Cell&) const;
	bool isOccupiedBySameSidePiece(const Cell&) const;

	std::vector<Move> generateValidPieceMoves(const Piece& piece, const Cell& cell) const;

	/**
	 * AI API
	 */
	std::vector<Move> calculateAllAvailableMoves(Side side) const;

private:
	CellToPieceLookup board;
	Side currentSide = Side::WHITE;
	PieceMoveGenerator moveGen;

	void movePiece(const Cell& source, const Cell& destination);
	double scoreMove(const Cell& destination) const;

	friend std::ostream& operator<<(std::ostream&, const ChessBoard&);
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_ */

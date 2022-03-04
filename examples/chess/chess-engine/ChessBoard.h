#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_

#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::unordered_map<Cell, Piece, Cell::HashFunction> CellToPieceLookup;

class ChessBoard {
public:
	ChessBoard();
	~ChessBoard() = default;

	const CellToPieceLookup& getPiecePositions() const;

	bool makeMove(const Cell& source, const Cell& destination);

	std::vector<Move> calculateMovesForPiece(const Cell& source) const;

	/**
	 * Whether a move is valid based on physical rules:
	 * 1. On the source cell the piece is on move
	 * 2. Is source and destination are in the borders of the board
	 * 3. The source cell is not empty.
	 * 4. The destination cell is either empty or an enemy.
	 */
	bool isValidMove(const Cell& source, const Cell& destination) const;

	/**
	 * Whether a move is valid in terms of piece movement rules and general chess rules: check, etc.
	 */
	bool isAllowedMove(const Cell& source, const Cell& destination) const;

	Side switchSide();

	void setBoard();

	const Piece& getPieceOnCell(const Cell& source) const;

	/**
	 * AI API
	 */
	std::vector<Move> calculateAllAvailableMoves(Side side) const;

private:
	CellToPieceLookup board;
	Side currentSide = Side::WHITE;

	const int32_t BOARD_SIZE = 8;

	bool isInBounds(const Cell& cell) const;
	bool isEmptyCell(const Cell& cell) const;
	bool isFriendlyCell(const Cell& cell) const;
	void movePiece(const Cell& source, const Cell& destination);

	double scoreMove(const Cell& destination) const;

	friend std::ostream& operator<<(std::ostream& os, const ChessBoard& chessBoard);

	std::vector<Move> generateValidPieceMoves(const Piece& piece, const Cell& cell) const;
	std::vector<Cell> generatePieceMoves(Piece piece, Cell source) const;
	std::vector<Cell> generateKnightMoves(Cell& knightPosition) const;
	std::vector<Cell> generateRookMoves(Cell& currentCell) const;
	std::vector<Cell> generateBishopMoves(Cell& currentCell) const;
	std::vector<Cell> generateQueenMoves(Cell& currentCell) const;
	std::vector<Cell> generatePawnMoves(Cell& currentCell, Side side) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSBOARD_H_ */

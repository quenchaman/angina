#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include <iostream>
#include <unordered_map>
#include <vector>

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Move.h"

typedef std::unordered_map<Cell, Piece, Cell::HashFunction> PiecePositions;

class ChessEngine {
public:
	ChessEngine();
	~ChessEngine() = default;

	const PiecePositions& getPiecePositions() const;

	bool makeMove(const Cell& source, const Cell& destination);

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

	/**
	 * AI API
	 */
	std::vector<Move> calculateAllAvailableMoves(Side side) const;

private:
	PiecePositions board;
	Side currentSide = Side::WHITE;

	const int32_t BOARD_SIZE = 8;

	void setBoard();
	bool isInBounds(const Cell& cell) const;
	bool isEmptyCell(const Cell& cell) const;
	bool isFriendlyCell(const Cell& cell) const;
	void movePiece(const Cell& source, const Cell& destination);

	friend std::ostream& operator<<(std::ostream& os, const ChessEngine& chessEngine);

	/**
	 * Piece movement helpers
	 */
	std::vector<Cell> generatePieceMoves(Piece piece, Cell source) const;
	std::vector<Cell> generateKnightMoves(Cell& knightPosition) const;
	std::vector<Cell> generateRookMoves(Cell& currentCell) const;
	std::vector<Cell> generateBishopMoves(Cell& currentCell) const;
	std::vector<Cell> generateQueenMoves(Cell& currentCell) const;
	std::vector<Cell> generatePawnMoves(Cell& currentCell, Side side) const;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */

#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_

#include <vector>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

struct ChessBoard;

/**
 * Methods to get the moves for a piece which are not outside the board and not over friendly piece.
 */
class PieceMoveGenerator {
public:
	PieceMoveGenerator(ChessBoard&);

	std::vector<Cell> generatePieceMoves(Piece, Cell source) const;
	std::vector<Cell> generateKnightMoves(Cell& knightPosition) const;
	std::vector<Cell> generateRookMoves(Cell& currentCell) const;
	std::vector<Cell> generateBishopMoves(Cell& currentCell) const;
	std::vector<Cell> generateQueenMoves(Cell& currentCell) const;
	std::vector<Cell> generatePawnMoves(Cell& currentCell, Side) const;

private:
	ChessBoard& board;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECEMOVEGENERATOR_H_ */

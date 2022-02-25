#ifndef EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_

#include <unordered_map>

#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Side.h"

typedef std::unordered_map<Cell, Piece, Cell::HashFunction> PiecePositions;

class ChessEngine {
public:
	ChessEngine();
	~ChessEngine();

	const PiecePositions& getPiecePositions() const;

	void makeMove(Cell source, Cell destination);
private:
	PiecePositions board;
	Side currentSide;

	const int32_t BOARD_SIZE = 8;

	void setBoard();
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_CHESSENGINE_H_ */

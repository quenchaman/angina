#ifndef CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_
#define CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_

#include <vector>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Cell.h"
#include "examples/chess/chess-engine/Rank.h"

class PieceMoveGenerator {
public:
	static std::vector<Move> generatePieceMoves(Rank& rank, Cell& source);
private:
	static std::vector<Move> generateKnightMoves(Cell& knightPosition);

	static std::vector<Move> generateRookMoves(Cell& currentCell);
	static void generateRookMoves(Cell& currentCell, );
};

#endif /* CHESS_GAME_PIECES_PIECEMOVEGENERATOR_H_ */

#ifndef CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_
#define CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_

#include <vector>

#include "examples/chess/chess-engine/Move.h"
#include "examples/chess/chess-engine/Side.h"

struct Board;
struct Piece;

class ValidMovesGenerator {
public:
	ValidMovesGenerator(Board& board);

	std::vector<Move> generatePieceMoves(Piece piece) const;
private:
	Board& _board;
};

#endif /* CHESS_GAME_PIECES_VALIDMOVESGENERATOR_H_ */

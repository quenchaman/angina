#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_

#include "examples/chess/chess-engine/Rank.h"
#include "examples/chess/chess-engine/Side.h"

struct Piece {
	Rank rank;
	Side side;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_ */

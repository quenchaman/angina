#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_

#include "examples/chess/chess-engine/Rank.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Cell.h"

struct Piece {
	Rank rank;
	Side side;

	static const Piece WHITE_ROOK;
	static const Piece WHITE_KNIGHT;
	static const Piece WHITE_BISHOP;
	static const Piece WHITE_PAWN;
	static const Piece WHITE_QUEEN;
	static const Piece WHITE_KING;

	static const Piece BLACK_ROOK;
	static const Piece BLACK_KNIGHT;
	static const Piece BLACK_BISHOP;
	static const Piece BLACK_PAWN;
	static const Piece BLACK_QUEEN;
	static const Piece BLACK_KING;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_ */

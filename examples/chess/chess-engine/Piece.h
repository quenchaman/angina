#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_

#include "examples/chess/chess-engine/Rank.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Cell.h"

// This class is not going to work well with map because we have multiple equal pieces.
// Maybe it would be better to have the Cell position on the piece itself....
struct Piece {
	Rank rank;
	Side side;

	bool operator==(const Piece& other) const;
	bool operator!=(const Piece& other) const;

	struct HashFunction {
		size_t operator ()(const Piece& piece) const {
			size_t rankHash = std::hash<Rank>()(piece.rank);
			size_t sideHash = std::hash<Side>()(piece.side) << 16;

			return rankHash ^ sideHash;
		}
	};

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

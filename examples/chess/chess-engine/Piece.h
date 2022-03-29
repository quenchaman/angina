#ifndef EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_
#define EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_

#include <unordered_map>
#include <string>
#include <iostream>

#include "examples/chess/chess-engine/Rank.h"
#include "examples/chess/chess-engine/Side.h"
#include "examples/chess/chess-engine/Cell.h"

struct Piece {
	Rank rank;
	Side side;
	bool operator==(const Piece &other) const;
	bool operator!=(const Piece &other) const;

	std::string serialize() const;

	struct HashFunction {
		size_t operator ()(const Piece &piece) const {
			size_t rankHash = std::hash<Rank>()(piece.rank);
			size_t sideHash = std::hash<Side>()(piece.side) << 16;

			return rankHash ^ sideHash;
		}
	};

	friend std::ostream& operator<<(std::ostream&, const Piece&);

	friend void operator>>(std::istream&, Piece&);

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

	static const std::unordered_map<Rank, std::string> rankToString;
	static const std::unordered_map<Rank, int32_t> rankToCost;
};

#endif /* EXAMPLES_CHESS_CHESS_ENGINE_PIECE_H_ */

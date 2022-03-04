#include "Piece.h"

const Piece Piece::WHITE_ROOK{Rank::ROOK, Side::WHITE};
const Piece Piece::WHITE_BISHOP{Rank::BISHOP, Side::WHITE};
const Piece Piece::WHITE_KNIGHT{Rank::KNIGHT, Side::WHITE};
const Piece Piece::WHITE_PAWN{Rank::PAWN, Side::WHITE};
const Piece Piece::WHITE_KING{Rank::KING, Side::WHITE};
const Piece Piece::WHITE_QUEEN{Rank::QUEEN, Side::WHITE};

const Piece Piece::BLACK_ROOK{Rank::ROOK, Side::BLACK};
const Piece Piece::BLACK_BISHOP{Rank::BISHOP, Side::BLACK};
const Piece Piece::BLACK_KNIGHT{Rank::KNIGHT, Side::BLACK};
const Piece Piece::BLACK_PAWN{Rank::PAWN, Side::BLACK};
const Piece Piece::BLACK_QUEEN{Rank::QUEEN, Side::BLACK};
const Piece Piece::BLACK_KING{Rank::KING, Side::BLACK};

bool Piece::operator==(const Piece& other) const {
	return rank == other.rank && side == other.side;
}

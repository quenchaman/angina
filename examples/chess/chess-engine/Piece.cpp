#include "Piece.h"

const Piece Piece::WHITE_ROOK { Rank::ROOK, Side::WHITE };
const Piece Piece::WHITE_BISHOP { Rank::BISHOP, Side::WHITE };
const Piece Piece::WHITE_KNIGHT { Rank::KNIGHT, Side::WHITE };
const Piece Piece::WHITE_PAWN { Rank::PAWN, Side::WHITE };
const Piece Piece::WHITE_KING { Rank::KING, Side::WHITE };
const Piece Piece::WHITE_QUEEN { Rank::QUEEN, Side::WHITE };

const Piece Piece::BLACK_ROOK { Rank::ROOK, Side::BLACK };
const Piece Piece::BLACK_BISHOP { Rank::BISHOP, Side::BLACK };
const Piece Piece::BLACK_KNIGHT { Rank::KNIGHT, Side::BLACK };
const Piece Piece::BLACK_PAWN { Rank::PAWN, Side::BLACK };
const Piece Piece::BLACK_QUEEN { Rank::QUEEN, Side::BLACK };
const Piece Piece::BLACK_KING { Rank::KING, Side::BLACK };

bool Piece::operator==(const Piece &other) const {
	return rank == other.rank && side == other.side;
}

bool Piece::operator!=(const Piece &other) const {
	return !(*this == other);
}

std::string Piece::serialize() const {
	return std::string() + std::to_string(rank) + " " + std::to_string(side);
}

std::ostream& operator<<(std::ostream &os, const Piece &piece) {
	return os << "The piece is with rank " << Piece::rankToString.at(piece.rank)
			<< " and side " << piece.side;
}

void operator>>(std::istream& is, Piece& piece) {
    int rank, side;
    is >> rank >> side;

    piece.rank = static_cast<Rank>(rank);
    piece.side = static_cast<Side>(side);
}

const std::unordered_map<Rank, std::string> Piece::rankToString = { {
		Rank::PAWN, "pawn" }, { Rank::BISHOP, "bishop" }, { Rank::KING, "king" }, {
		Rank::KNIGHT, "knight" }, { Rank::QUEEN, "queen" }, { Rank::ROOK, "rook" } };

const std::unordered_map<Rank, int32_t> Piece::rankToCost = { { Rank::PAWN, 1 },
		{ Rank::BISHOP, 3 }, { Rank::KING, -1 }, { Rank::KNIGHT, 3 }, { Rank::QUEEN,
				9 }, { Rank::ROOK, 5 } };

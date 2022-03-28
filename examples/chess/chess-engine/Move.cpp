#include "Move.h"

#include "examples/chess/CellUtils.h"

const Move Move::UNDEFINED(Cell::UNDEFINED, Cell::UNDEFINED, 0.0, Side::NA);

Move::Move(Cell src, Cell dst, double scr, Side moveSide) :
        source(src), destination(dst), score(scr), side(moveSide) {
}

bool Move::operator==(const Move &other) const {
    return source == other.source && destination == other.destination;
}

bool Move::operator!=(const Move &other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream &os, const Move &move) {
	return os << ((move.side == Side::WHITE) ? "White" : "Black") << ": From " << CellUtils::toChessCoordinates(move.source)
			<< ", To "<< CellUtils::toChessCoordinates(move.destination) << " and the score is " << move.score;
}

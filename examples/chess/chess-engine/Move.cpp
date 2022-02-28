#include "Move.h"

Move::Move(Cell src, Cell dst): source(src), destination(dst) {
}

bool Move::operator==(const Move& other) const {
	return source == other.source && destination == other.destination;
}

bool Move::operator!=(const Move& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Move& move) {
	return os << "Move start: " << move.source << "; Move end:" << move.destination;
}

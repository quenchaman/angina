#include "Move.h"

const Move Move::UNDEFINED(Cell::UNDEFINED, Cell::UNDEFINED, 0.0);

Move::Move(Cell src, Cell dst, double scr) :
        source(src), destination(dst), score(scr) {
}

bool Move::operator==(const Move &other) const {
    return source == other.source && destination == other.destination;
}

bool Move::operator!=(const Move &other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream &os, const Move &move) {
    return os << "Move start: " << move.source << "; Move end:"
            << move.destination << " and the score is " << move.score;
}

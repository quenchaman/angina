/*
 * Move.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#include "Move.h"

Move::Move(Cell _src, Cell _dst): src(_src), dst(_dst) {
}

std::ostream& operator<<(std::ostream& os, const Move& move) {
	return os << "Move start: " << move.src << "; Move end:" << move.dst;
}

bool Move::operator==(const Move& other) const {
	return src == other.src && dst == other.dst;
}

bool Move::operator!=(const Move& other) const {
	return !(*this == other);
}

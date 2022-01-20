/*
 * Piece.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "Piece.h"

#include "sdl/engine/object/Object.h"

Piece::Piece(Object& _object, Cell _cell, Side _side, Rank _rank): object(_object), cell(_cell), side(_side), rank(_rank), hasMoved(false) {}

void Piece::move(const Point point, const Cell dst) {
	object.move(point.x, point.y);
	cell = dst;
}

std::ostream& operator<<(std::ostream& os, const Piece& piece) {
	return os << "Position: " << piece.cell << "; Rank: " << piece.rank << "; Side: " << piece.side;
}


#include "Pawn.h"

Pawn::Pawn(int32_t _col, int32_t _row, Side _side, Image* _image): Piece(_col, _row, Rank::PAWN, _side, _image) {}

std::vector<Cell> Pawn::calculateMoves() { return {}; }

Pawn::~Pawn() {

}

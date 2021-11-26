
#include "Pawn.h"

Pawn::Pawn(int32_t _id, int32_t _col, int32_t _row, Side _side, Texture* _texture): Piece(_id, _col, _row, Rank::PAWN, _side, _texture) {}

std::vector<Cell> Pawn::calculateMoves() { return {}; }

Pawn::~Pawn() {

}

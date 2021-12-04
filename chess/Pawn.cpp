
#include "Pawn.h"

Pawn::Pawn(int32_t _col, int32_t _row, Side _side, Image* _image): Piece(_col, _row, Rank::PAWN, _side, _image) {}

std::vector<Cell> Pawn::calculateMoves(std::map<Cell, Piece*> boardPieces) {
	std::vector<Cell> moves;
	moves.reserve(boardPieces.size());
	if (getSide() == Side::White) {
		moves.push_back({ getCol(), getRow() - 1 });
		moves.push_back({ getCol(), getRow() - 2 });
		moves.push_back({ getCol() - 1, getRow() - 1 });
		moves.push_back({ getCol() + 1, getRow() - 1 });
	} else {
		moves.push_back({ getCol(), getRow() + 1 });
		moves.push_back({ getCol(), getRow() + 2 });
		moves.push_back({ getCol() - 1, getRow() + 1 });
		moves.push_back({ getCol() + 1, getRow() + 1 });
	}

	return moves;
}

Pawn::~Pawn() {
}

bool Pawn::isOnInitialPosition() {
    return this->getSide() == Side::White ? (getRow() == 6) : (getRow() == 1);
}

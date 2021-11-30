
#include "Pawn.h"

Pawn::Pawn(int32_t _col, int32_t _row, Side _side, Image* _image): Piece(_col, _row, Rank::PAWN, _side, _image) {}

std::vector<Cell> Pawn::calculateMoves(std::map<Cell, Piece*> boardPieces) {
	std::vector<Cell> moves;
	if (getSide() == Side::White) {
		moves.push_back({ piecePos.col, piecePos.row - 1 });
		moves.push_back({ piecePos.col, piecePos.row - 2 });
		moves.push_back({ piecePos.col - 1, piecePos.row - 1 });
		moves.push_back({ piecePos.col + 1, piecePos.row - 1 });
	} else {
		moves.push_back({ piecePos.col, piecePos.row + 1 });
		moves.push_back({ piecePos.col, piecePos.row + 2 });
		moves.push_back({ piecePos.col - 1, piecePos.row + 1 });
		moves.push_back({ piecePos.col + 1, piecePos.row + 1 });
	}

	return moves;
}

Pawn::~Pawn() {

}

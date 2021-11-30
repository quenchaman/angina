//
// Created by ubuntu on 11/25/21.
//

#include "King.h"

King::King(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::KING, _side, _image) {

}

King::~King() {
}

std::vector<Cell> King::calculateMoves(std::map<Cell, Piece*> boardPieces) {
    std::vector<Cell> moves;
    moves.reserve(boardPieces.size());

    moves.push_back({ getCol(), getRow() - 1 });
	moves.push_back({ getCol() + 1, getRow() - 1 });
	moves.push_back({ getCol() + 1, getRow() });
	moves.push_back({ getCol() + 1, getRow() + 1 });
	moves.push_back({ getCol(), getRow() + 1 });
	moves.push_back({ getCol() - 1, getRow() + 1 });
	moves.push_back({ getCol() - 1, getRow() });
	moves.push_back({ getCol() - 1, getRow() - 1 });

	return moves;
}

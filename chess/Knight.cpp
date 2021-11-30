//
// Created by ubuntu on 11/25/21.
//

#include "Knight.h"

Knight::Knight(int32_t _col, int32_t _row, Side _side, Image* _image) : Piece(_col, _row, Rank::KNIGHT, _side, _image) {

}

Knight::~Knight() {

}

std::vector<Cell> Knight::calculateMoves(std::map<Cell, Piece*> boardPieces) {
    std::vector<Cell> moves;
    moves.reserve(boardPieces.size());

    moves.push_back({ getCol() - 2, getRow() - 1 });
	moves.push_back({ getCol() - 1, getRow() - 2 });
	moves.push_back({ getCol() + 1, getRow() - 2 });
	moves.push_back({ getCol() + 2, getRow() - 1 });
	moves.push_back({ getCol() + 2, getRow() + 1 });
	moves.push_back({ getCol() + 1, getRow() + 2 });
	moves.push_back({ getCol() - 1, getRow() + 2 });
	moves.push_back({ getCol() - 2, getRow() + 1 });

	return moves;
}

//
// Created by ubuntu on 11/25/21.
//

#include "Queen.h"

Queen::Queen(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::QUEEN, _side, _image) {

}

Queen::~Queen() {

}

std::vector<Cell> Queen::calculateMoves(std::map<Cell, Piece*> boardPieces) {
	moves.reserve(boardPieces.size());

	Rook* rook = new Rook(getCol(), getRow(), getSide(), getImage());
	Bishop* bishop = new Bishop(getCol(), getRow(), getSide(), getImage());
	std::vector<Cell> rookMoves = rook->calculateMoves(boardPieces);

	moves.insert(std::end(moves), std::begin(rookMoves), std::end(rookMoves));

	std::vector<Cell> bishopMoves = bishop->calculateMoves(boardPieces);

	moves.insert(std::end(moves), std::begin(bishopMoves), std::end(bishopMoves));

	delete rook;
	delete bishop;

    return moves;
}

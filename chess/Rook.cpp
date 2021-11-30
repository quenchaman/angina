//
// Created by ubuntu on 11/25/21.
//

#include "Rook.h"

Rook::Rook(int32_t _col, int32_t _row, Side _side, Image *_image): Piece(_col, _row, Rank::ROOK, _side, _image) {

}

Rook::~Rook() {

}

std::vector<Cell> Rook::calculateMoves(std::map<Cell, Piece*> boardPieces) {
	moves.clear();
    calculateMoves(boardPieces, {getCol(), getRow()});
    return moves;
}

void Rook::calculateMoves(std::map<Cell, Piece*> boardPieces, Cell currentCell) {
	// Check if we are outside of board's bounds
	if (currentCell.col < 0 || currentCell.row < 0 || currentCell.col > 7 || currentCell.row > 7) {
		return;
	}

	// Check if we are on a enemy piece, consume it and return
	if (boardPieces[currentCell] != nullptr && boardPieces[currentCell]->getSide() != getSide()) {
		moves.push_back(currentCell);
		return;
	}

	// Check if we are on friendly piece, do not  add this as a move
	if (boardPieces[currentCell] != nullptr && boardPieces[currentCell]->getSide() == getSide()) {
		return;
	}

	moves.push_back(currentCell);

	Cell up = { currentCell.col, currentCell.row - 1 };
	calculateMoves(boardPieces, up);

	Cell right = { currentCell.col + 1, currentCell.row };
	calculateMoves(boardPieces, right);

	Cell down = { currentCell.col, currentCell.row + 1 };
	calculateMoves(boardPieces, down);

	Cell left = { currentCell.col - 1, currentCell.row };
	calculateMoves(boardPieces, left);
}

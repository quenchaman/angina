//
// Created by ubuntu on 11/25/21.
//

#include "Bishop.h"

Bishop::Bishop(int32_t _col, int32_t _row, Side _side, Image* _image): Piece(_col, _row, Rank::BISHOP, _side, _image) {

}

Bishop::~Bishop() {

}

std::vector<Cell> Bishop::calculateMoves(std::map<Cell, Piece*> boardPieces) {
    return std::vector<Cell>();
}

void Bishop::calculateMoves(std::map<Cell, Piece*> boardPieces, Cell currentCell) {
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

	Cell topRight = { currentCell.col + 1, currentCell.row - 1 };
	calculateMoves(boardPieces, topRight);

	Cell bottomRight = { currentCell.col + 1, currentCell.row + 1 };
	calculateMoves(boardPieces, bottomRight);

	Cell bottomLeft = { currentCell.col - 1, currentCell.row + 1 };
	calculateMoves(boardPieces, bottomLeft);

	Cell topLeft = { currentCell.col - 1, currentCell.row - 1 };
	calculateMoves(boardPieces, topLeft);
}

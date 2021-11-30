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
    _calculateMoves(boardPieces);
    return moves;
}

void Rook::_calculateMoves(std::map<Cell, Piece*> boardPieces) {
	// Go north and add moves
	for (int32_t rowIdx = getRow() - 1; rowIdx >= 0; rowIdx--) {
		Cell currentCell = {getCol(), rowIdx};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Go east and add moves
	for (int32_t colIdx = getCol() + 1; colIdx < 8; colIdx++) {
		Cell currentCell = {colIdx, getRow()};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Go south and add moves
	for (int32_t rowIdx = getRow() + 1; rowIdx < 8; rowIdx++) {
		Cell currentCell = {getCol(), rowIdx};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Go east and add moves
	for (int32_t colIdx = getCol() - 1; colIdx >= 0; colIdx--) {
		Cell currentCell = {colIdx, getRow()};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}
}

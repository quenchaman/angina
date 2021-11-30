//
// Created by ubuntu on 11/25/21.
//

#include "Bishop.h"

Bishop::Bishop(int32_t _col, int32_t _row, Side _side, Image* _image): Piece(_col, _row, Rank::BISHOP, _side, _image) {

}

Bishop::~Bishop() {
}

std::vector<Cell> Bishop::calculateMoves(std::map<Cell, Piece*> boardPieces) {
	moves.clear();
	_calculateMoves(boardPieces);
    return moves;
}

void Bishop::_calculateMoves(std::map<Cell, Piece*> boardPieces) {
	// Let's go top right and check for moves
	int32_t row = getRow() - 1;
	int32_t col = getCol() + 1;
	for (; col < 8 && row >= 0; col++, row--) {
		Cell currentCell = {col, row};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Let's go bottom right
	row = getRow() + 1;
	col = getCol() + 1;
	for (; col < 8 && row < 8; col++, row++) {
		Cell currentCell = {col, row};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Let's go bottom left
	row = getRow() + 1;
	col = getCol() - 1;
	for (; col >= 0 && row < 8; col--, row++) {
		Cell currentCell = {col, row};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (currentCellPiece != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}

	// Let's go top left
	row = getRow() - 1;
	col = getCol() - 1;
	for (; col >= 0 && row >= 0; col--, row--) {
		Cell currentCell = {col, row};
		Piece* currentCellPiece = boardPieces[currentCell];

		if (boardPieces[currentCell] != nullptr) {
			if (getSide() != currentCellPiece->getSide()) {
				moves.push_back(currentCell);
			}

			break;
		}

		moves.push_back(currentCell);
	}
}

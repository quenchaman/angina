/*
 * Piece.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: ubuntu
 */

#include "Piece.h"

Piece::Piece(int32_t _id, int32_t _col, int32_t _row, Rank _rank, Side _side, Texture* texture):
	id(_id), col(_col), row(_row), rank(_rank), side(_side) {

	image = new Image(*texture, { _col * Piece::PIECE_WIDTH,
                                  _row * Piece::PIECE_HEIGHT,
                                  Piece::PIECE_WIDTH,
                                  Piece::PIECE_HEIGHT });
}

void Piece::move(Cell cell) {
	this->col = cell.col;
	this->row = cell.row;

	this->image->setX(col * Piece::PIECE_WIDTH);
	this->image->setY(row * Piece::PIECE_HEIGHT);
}

int32_t Piece::getCol() {
	return col;
}

int32_t Piece::getRow() {
	return row;
}

Rank Piece::getRank() {
	return rank;
}

Side Piece::getSide() {
	return side;
}

Image* Piece::getImage() {
	return image;
}

void Piece::draw(Renderer& renderer) {
	image->draw(renderer);
}

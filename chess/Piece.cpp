/*
 * Piece.cpp
 *
 *  Created on: Nov 19, 2021
 *      Author: ubuntu
 */

#include "Piece.h"

Piece::Piece(int32_t _col, int32_t _row, Rank _rank, Side _side, Image* _image):
col(_col), row(_row), rank(_rank), side(_side), initCol(_col), initRow(_row), image(_image) {
    move({_col, _row});
}

void Piece::move(Cell cell) {
	this->col = cell.col;
	this->row = cell.row;

	this->image->setX(col * Piece::PIECE_WIDTH);
	this->image->setY(row * Piece::PIECE_HEIGHT);

    std::cout << "x = " << this->image->getBoundingBox().x << "; y = " << this->image->getBoundingBox().y << std::endl;
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

Cell Piece::getCell() {
	return {getCol(), getRow()};
}

bool Piece::getHasMoved() {
	return getCol() != initCol || getRow() != initRow;
}

void Piece::draw(Renderer &renderer, double angle) {
    image->draw(renderer, angle);
}

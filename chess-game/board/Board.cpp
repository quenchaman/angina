/*
 * Board.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "Board.h"

#include <cstdint>

#include "sdl/engine/object/Object.h"

Board::Board(Object& object, Dimensions cellDimensions): _object(object), _cellDimensions(cellDimensions) {}

void Board::draw() {
	_object.draw();

	for (auto const& [pos, piece] : _piecePositions) {
		piece->object.draw();
	}
}

Point Board::putPiece(Piece& piece) {
	Point boardOrigin = _object.getPosition();

	int32_t pieceX = boardOrigin.x + (piece.cell.col * _cellDimensions.w);
	int32_t pieceY = boardOrigin.y + (piece.cell.row * _cellDimensions.h);

	Point piecePoint = { pieceX, pieceY };
	piece.object.move(pieceX, pieceY);
	_piecePositions[piecePoint] = &piece;

	return piecePoint;
}

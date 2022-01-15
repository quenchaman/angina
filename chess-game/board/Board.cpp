/*
 * Board.cpp
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#include "Board.h"

#include <cstdint>
#include <iostream>

#include "sdl/engine/object/Object.h"
#include "sdl/primitives/Rect.h"
#include "sdl/primitives/Dimensions.h"
#include "sdl/primitives/Color.h"

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
	Cell c = getCell(piecePoint);
	_piecePositions[c] = &piece;

	return piecePoint;
}

bool Board::isBoardPosition(Point point) {
	return this->_object.rectangle.isInRect(point);
}

bool Board::isBoardPosition(Cell cell) {
	return cell.row >= 0 && cell.col >= 0 && cell.row <= 7 && cell.col <= 7;
}

Cell Board::getCell(Point point) {
	Point boardOrigin = _object.getPosition();
	int32_t pieceX = (point.x - boardOrigin.x) / _cellDimensions.w;
	int32_t pieceY = (point.y - boardOrigin.y) / _cellDimensions.h;

	return {pieceX, pieceY};
}

bool Board::isEmptyCell(Cell cell) {
	return _piecePositions.find(cell) == _piecePositions.end();
}

Piece* Board::getPieceOnPosition(Cell cell) {
	if (!isEmptyCell(cell)) {
		return _piecePositions.find(cell)->second;
	}

	return nullptr;
}

bool Board::isSidePieceSelected(Point point, Side side) {
	if (isBoardPosition(point)) {
		Piece* selectedPiece = getPieceOnPosition(getCell(point));

		if (selectedPiece == nullptr) {
			return false;
		}

		if (selectedPiece->side == side) {
			return true;
		}
	}

	return false;
}

bool Board::isSidePieceSelected(Cell cell, Side side) {
	return isSidePieceSelected(calculatePoint(cell), side);
}

Point Board::calculatePoint(Cell cell) {
	return { cell.row * _cellDimensions.h, cell.col * _cellDimensions.w };
}

void Board::setAvailableMoveCells(std::vector<Move> moves) {
	for (auto& move : moves) {
		availableMoveCells.push_back(cellToRect(move.dst));
	}
}

Rect Board::cellToRect(Cell move) {
	Point p = calculatePoint(move);
	return Rect(p, Dimensions{_cellDimensions.w, _cellDimensions.h}, Color::GREEN);
}

Board::~Board() {
	for (auto const& [cell, piece] : _piecePositions) {
		delete piece;
	}
	_piecePositions.clear();

	std::cout << "Board destroyed" << std::endl;
}

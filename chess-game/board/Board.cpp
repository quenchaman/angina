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
#include "sdl/graphics/Renderer.h"
#include "chess-game/board/CellUtils.h"

Board::Board(Object& object, Dimensions cellDimensions): _object(object), _cellDimensions(cellDimensions) {}

void Board::draw(const Renderer& renderer) const {
	_object.draw();

	for (auto const& [pos, piece] : _piecePositions) {
		piece->object.draw();
	}

	for (auto& rect : availableMoveRects) {
		renderer.render(rect);
	}
}

Point Board::putPiece(Piece& piece) {
	Point piecePoint = CellUtils::cellToPoint(piece.cell, _cellDimensions, _object.getPosition());

	piece.object.move(piecePoint.x, piecePoint.y);

	_piecePositions[piece.cell] = &piece;

	return piecePoint;
}

bool Board::isBoardPosition(Point point) {
	return this->_object.rectangle.isInRect(point);
}

bool Board::isBoardPosition(Cell cell) {
	return cell.row >= 0 && cell.col >= 0 && cell.row <= 7 && cell.col <= 7;
}

Cell Board::getCell(Point point) {
	return CellUtils::pointToCell(point, _cellDimensions, _object.getPosition());
}

bool Board::isEmptyCell(Cell cell) const {
	return _piecePositions.find(cell) == _piecePositions.end();
}

Piece* Board::getPieceOnPosition(Cell cell) const {
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
	return isSidePieceSelected(CellUtils::cellToPoint(cell, _cellDimensions, _object.getPosition()), side);
}

void Board::setAvailableMoveCells(std::vector<Move> moves) {
	clearAvailableMoves();
	availableMoveRects.reserve(moves.size());
	availableMoves.reserve(moves.size());

	for (auto& move : moves) {
		availableMoveRects.push_back(cellToRect(move.dst));
		availableMoves.insert(move.dst);
	}
}

void Board::clearAvailableMoves() {
	availableMoveRects.clear();
	availableMoves.clear();
}

Rect Board::cellToRect(Cell move) {
	Point p = CellUtils::cellToPoint(move, _cellDimensions, _object.getPosition());

	return Rect(p, Dimensions{_cellDimensions.w, _cellDimensions.h}, HIGHLIGHTED_CELL_COLOR);
}

void Board::movePiece(Piece* piece, Cell destination) {
	_piecePositions.erase(piece->cell);

	piece->move(CellUtils::cellToPoint(destination, _cellDimensions, _object.getPosition()), destination);

	_piecePositions[destination] = piece;
}

bool Board::isAllowedMove(Cell move) const {
	return availableMoves.find(move) != availableMoves.end();
}

void Board::capturePiece(Cell position) {
	if (!isEmptyCell(position)) {
		_piecePositions.erase(position);
	}
}

std::vector<Piece*> Board::getPiecesOfSide(Side side) const {
	std::vector<Piece*> pieces;

	for (auto const& [cell, piece] : _piecePositions) {
		if (piece->side == side) {
			pieces.push_back(piece);
		}
	}

	return pieces;
}

Board::~Board() {
	for (auto const& [cell, piece] : _piecePositions) {
		delete piece;
	}
	_piecePositions.clear();

	std::cout << "Board destroyed" << std::endl;
}

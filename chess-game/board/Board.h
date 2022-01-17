/*
 * Board.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_BOARD_BOARD_H_
#define CHESS_GAME_BOARD_BOARD_H_

#include <unordered_map>
#include <vector>

#include "chess-game/board/Cell.h"
#include "chess-game/pieces/Piece.h"
#include "chess-game/pieces/Move.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Rect.h"
#include "sdl/primitives/Dimensions.h"

struct Object;
struct Renderer;

struct CellHasher {
	size_t operator() (const Cell& point) const {
		return (point.row * 10) + point.col;
	}
};

class Board {
public:
	Board(Object& object, Dimensions cellDimensions);
	~Board();

	void draw(Renderer* renderer);

	Point putPiece(Piece& piece);

	bool isBoardPosition(Point point);
	bool isBoardPosition(Cell cell);
	Cell getCell(Point point);
	bool isEmptyCell(Cell cell);
	Piece* getPieceOnPosition(Cell cell);
	bool isSidePieceSelected(Point point, Side side);
	bool isSidePieceSelected(Cell cell, Side side);
	Point calculatePoint(Cell cell);
	void setAvailableMoveCells(std::vector<Move> moves);
private:
	Object& _object;
	Dimensions _cellDimensions;
	std::unordered_map<Cell, Piece*, CellHasher> _piecePositions;
	std::vector<Rect> availableMoveCells;

	Rect cellToRect(Cell move);
};

#endif /* CHESS_GAME_BOARD_BOARD_H_ */

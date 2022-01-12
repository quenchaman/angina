/*
 * Board.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_BOARD_BOARD_H_
#define CHESS_GAME_BOARD_BOARD_H_

#include <unordered_map>

#include "chess-game/board/Cell.h"
#include "chess-game/pieces/Piece.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

struct Object;

struct CellHasher {
	size_t operator() (const Cell& point) const {
		return (point.row * 10) + point.col;
	}
};

class Board {
public:
	Board(Object& object, Dimensions cellDimensions);
	~Board();

	void draw();

	Point putPiece(Piece& piece);

	bool isBoardPosition(Point point);
	Cell getCell(Point point);
	bool isEmptyCell(Cell cell);
private:
	Object& _object;
	Dimensions _cellDimensions;
	std::unordered_map<Cell, Piece*, CellHasher> _piecePositions;
};

#endif /* CHESS_GAME_BOARD_BOARD_H_ */

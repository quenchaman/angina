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

struct PointHasher {
	size_t operator() (const Point& point) const {
		return (point.x * 10) + point.y;
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
	bool isEmptyCell(Point cell);
private:
	Object& _object;
	Dimensions _cellDimensions;
	std::unordered_map<Point, Piece*, PointHasher> _piecePositions;
};

#endif /* CHESS_GAME_BOARD_BOARD_H_ */

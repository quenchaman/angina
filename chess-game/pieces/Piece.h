/*
 * Piece.h
 *
 *  Created on: Jan 8, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PIECES_PIECE_H_
#define CHESS_GAME_PIECES_PIECE_H_

#include <iostream>

#include "chess-game/board/Cell.h"
#include "chess-game/pieces/Side.h"
#include "chess-game/pieces/Rank.h"

struct Object;

struct Piece {
	Piece(Object& object, Cell cell, Side side, Rank rank);
	~Piece() = default;

	Object& object;
	Cell cell;
	Side side;
	Rank rank;
	bool hasMoved;

	friend std::ostream& operator<<(std::ostream& os, const Piece& piece);
};

#endif /* CHESS_GAME_PIECES_PIECE_H_ */

/*
 * Move.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_PIECES_MOVE_H_
#define CHESS_GAME_PIECES_MOVE_H_

#include "chess-game/board/Cell.h"

struct Move {
	Move(Cell src, Cell dst);

	Cell src;
	Cell dst;
};

#endif /* CHESS_GAME_PIECES_MOVE_H_ */

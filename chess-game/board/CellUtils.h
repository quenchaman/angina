/*
 * CellUtils.h
 *
 *  Created on: Jan 21, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_BOARD_CELLUTILS_H_
#define CHESS_GAME_BOARD_CELLUTILS_H_

#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

#include "chess-game/board/Cell.h"

namespace CellUtils {
	Point cellToPoint(Cell cell, Dimensions dim);
	Cell pointToCell(Point point, Dimensions dim);
}

#endif /* CHESS_GAME_BOARD_CELLUTILS_H_ */

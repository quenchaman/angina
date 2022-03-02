#ifndef CHESS_GAME_BOARD_CELLUTILS_H_
#define CHESS_GAME_BOARD_CELLUTILS_H_

#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"

#include "examples/chess/chess-engine/Cell.h"

namespace CellUtils {
	inline Point cellToPoint(Cell cell, Dimensions cellDimensions, Point offset = Point::ZERO);
	inline Cell pointToCell(Point point, Dimensions cellDimensions, Point offset = Point::ZERO);
}

#endif /* CHESS_GAME_BOARD_CELLUTILS_H_ */

/*
 * PieceSelectionManager.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ubuntu
 */

#ifndef CHESS_GAME_BOARD_PIECESELECTIONMANAGER_H_
#define CHESS_GAME_BOARD_PIECESELECTIONMANAGER_H_

#include "sdl/primitives/Point.h"
#include "chess-game/board/Cell.h"
#include "chess-game/states/ChessState.h"
#include "chess-game/pieces/Side.h"

struct Piece;
struct Board;

class PieceSelectionManager {
public:
	PieceSelectionManager(Board& board);
	~PieceSelectionManager() = default;

	void clearSelection();
	ChessState selectPiece(Point point);
	bool isSidePieceSelected(Point point, Side side);
private:
	Point clickedPoint = Point::UNDEFINED;
	Cell clickedBoardCell = Cell::UNDEFINED;
	Piece* selectedPiece = nullptr;

	Board& _board;
};

#endif /* CHESS_GAME_BOARD_PIECESELECTIONMANAGER_H_ */

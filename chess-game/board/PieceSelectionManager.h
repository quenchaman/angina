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

	void clearSelection();
	ChessState selectPiece(Point point);
	bool isSidePieceSelected(const Point point, const Side side) const;
	Piece* getSelectedPiece() const;
private:
	Point clickedPoint = Point::UNDEFINED;
	Cell clickedBoardCell = Cell::UNDEFINED;
	Piece* selectedPiece = nullptr;

	Board& _board;
};

#endif /* CHESS_GAME_BOARD_PIECESELECTIONMANAGER_H_ */

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
#include <unordered_set>

#include "chess-game/board/Cell.h"
#include "chess-game/pieces/Piece.h"
#include "chess-game/pieces/Move.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Rect.h"
#include "sdl/primitives/Dimensions.h"
#include "sdl/primitives/Color.h"

struct Object;
struct Renderer;

typedef std::unordered_map<Side, std::vector<Piece*>> PiecesBySide;

class Board {
public:
	Board(Object& object, Dimensions cellDimensions);
	~Board();

	void draw(const Renderer& renderer) const;

	Point putPiece(Piece& piece);

	bool isBoardPosition(Point point);

	bool isBoardPosition(Cell cell);

	Cell getCell(Point point);

	bool isEmptyCell(Cell cell) const;

	Piece* getPieceOnPosition(Cell cell) const;

	bool isSidePieceSelected(Point point, Side side);

	bool isSidePieceSelected(Cell cell, Side side);

	void setAvailableMoveCells(std::vector<Move> moves);

	bool isAllowedMove(Cell move) const;

	void clearAvailableMoves();

	void movePiece(Piece* piece, Cell destination);

	std::vector<Piece*> getPiecesOfSide(Side side) const;

	const PiecesBySide& getCapturedPieces() const;
private:
	Object& _object;
	Dimensions _cellDimensions;
	std::unordered_map<Cell, Piece*, Cell::CellHasher> _piecePositions;
	std::vector<Rect> availableMoveRects;
	std::unordered_set<Cell, Cell::HashFunction> availableMoves;
	PiecesBySide capturedPieces;

	const Color HIGHLIGHTED_CELL_COLOR = Color::RED;

	Rect cellToRect(Cell move);

	void capturePiece(Cell position);
};

#endif /* CHESS_GAME_BOARD_BOARD_H_ */

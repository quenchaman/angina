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
struct ValidMovesGenerator;

typedef std::unordered_map<Side, std::vector<Piece*>> PiecesBySide;

class Board {
public:
	Board(Object& object, Dimensions cellDimensions);
	~Board();

	void draw(const Renderer& renderer) const;

	Point putPiece(Piece& piece);

	bool isBoardPosition(Point point) const;

	bool isBoardPosition(Cell cell) const;

	Cell getCell(Point point) const;

	bool isEmptyCell(Cell cell) const;

	Piece* getPieceOnPosition(Cell cell) const;

	bool isSidePieceSelected(Point point, Side side) const;

	bool isSidePieceSelected(Cell cell, Side side) const;

	void setAvailableMoveCells(std::vector<Move> moves);

	bool isAllowedMove(Cell move) const;

	void clearAvailableMoves();

	void movePiece(Piece* piece, Cell destination);

	std::vector<Piece*> getPiecesOfSide(Side side) const;

	const PiecesBySide& getCapturedPieces() const;

	bool isAttacked(const Piece* piece, const ValidMovesGenerator& movesGenerator) const;

	bool isInBoardCenter(Cell cell) const;
private:
	Object& _object;
	Dimensions _cellDimensions;
	std::unordered_map<Cell, Piece*, Cell::HashFunction> _piecePositions;
	std::vector<Rect> availableMoveRects;
	std::unordered_set<Cell, Cell::HashFunction> availableMoves;
	PiecesBySide capturedPieces;

	const Color HIGHLIGHTED_CELL_COLOR = Color::RED;

	Rect cellToRect(Cell move);

	void capturePiece(Cell position);
};

#endif /* CHESS_GAME_BOARD_BOARD_H_ */

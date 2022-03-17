#include "BoundsMoveGenerator.h"

#include <iostream>

#include "examples/chess/chess-engine/ChessBoard.h"

BoundsMoveGenerator::BoundsMoveGenerator(ChessBoard& chessBoard): board(chessBoard) {}

CellUnorderedSet BoundsMoveGenerator::generatePieceMoves(const Piece& piece, const Cell& source) const {
	CellUnorderedSet moves;

	switch (piece.rank) {
		case Rank::KNIGHT:
			moves = generateKnightMoves(source);
			break;
		case Rank::ROOK:
			moves = generateRookMoves(source, piece.side);
			break;
		case Rank::BISHOP:
			moves = generateBishopMoves(source, piece.side);
			break;
		case Rank::PAWN:
			moves = generatePawnMoves(source, piece.side);
			break;
		case Rank::QUEEN:
			moves = generateQueenMoves(source, piece.side);
			break;
		// TODO: Add case for King
		default:
			break;
	}

	return moves;
}

CellUnorderedSet BoundsMoveGenerator::generateKnightMoves(const Cell& knightPosition) const {
	CellUnorderedSet m;
	m.reserve(8);

	m.insert(Cell{knightPosition.row - 2, knightPosition.col + 1});
	m.insert(Cell{knightPosition.row - 2, knightPosition.col - 1});

	m.insert(Cell{knightPosition.row + 2, knightPosition.col + 1});
	m.insert(Cell{knightPosition.row + 2, knightPosition.col - 1});

	m.insert(Cell{knightPosition.row - 1, knightPosition.col - 2});
	m.insert(Cell{knightPosition.row + 1, knightPosition.col - 2});

	m.insert(Cell{knightPosition.row - 1, knightPosition.col + 2});
	m.insert(Cell{knightPosition.row + 1, knightPosition.col + 2});

	return m;
}

CellUnorderedSet BoundsMoveGenerator::generateRookMoves(const Cell& currentCell, Side side) const {
	CellUnorderedSet destinationCells;

	/* Go top */
	Cell cellGoingTop = currentCell;
	cellGoingTop.moveTop();

	while (isValidMove(cellGoingTop, side)) {
		destinationCells.insert(cellGoingTop);
		cellGoingTop.moveTop();
	}

	/* Go right */
	Cell cellGoingRight = currentCell;
	cellGoingRight.moveRight();

	while (isValidMove(cellGoingRight, side)) {
		destinationCells.insert(cellGoingRight);
		cellGoingRight.moveRight();
	}

	/* Go down */
	Cell cellGoingDown = currentCell;
	cellGoingDown.moveDown();

	while (isValidMove(cellGoingDown, side)) {
		destinationCells.insert(cellGoingDown);
		cellGoingDown.moveDown();
	}

	/* Go left */
	Cell cellGoingLeft = currentCell;
	cellGoingLeft.moveLeft();

	while (isValidMove(cellGoingLeft, side)) {
		destinationCells.insert(cellGoingLeft);
		cellGoingLeft.moveLeft();
	}

	return destinationCells;
}

CellUnorderedSet BoundsMoveGenerator::generateBishopMoves(const Cell& currentCell, [[maybe_unused]]Side side) const {
	CellUnorderedSet destinationCells;

	/* Go top-left diagonal */
	Cell cellGoingTopLeft = currentCell;
	cellGoingTopLeft.moveTop().moveLeft();

	while (board.isInBounds(cellGoingTopLeft)) {
		destinationCells.insert(cellGoingTopLeft);
		cellGoingTopLeft.moveTop().moveLeft();
	}

	/* Go top-right */
	Cell cellGoingTopRight = currentCell;
	cellGoingTopRight.moveTop().moveRight();

	while (board.isInBounds(cellGoingTopRight)) {
		destinationCells.insert(cellGoingTopRight);
		cellGoingTopRight.moveRight().moveTop();
	}

	/* Go down-right */
	Cell cellGoingDownRight = currentCell;
	cellGoingDownRight.moveDown().moveRight();

	while (board.isInBounds(cellGoingDownRight)) {
		destinationCells.insert(cellGoingDownRight);
		cellGoingDownRight.moveDown().moveRight();
	}

	/* Go down-left */
	Cell cellGoingDownLeft = currentCell;
	cellGoingDownLeft.moveLeft().moveDown();

	while (board.isInBounds(cellGoingDownLeft)) {
		destinationCells.insert(cellGoingDownLeft);
		cellGoingDownLeft.moveLeft().moveDown();
	}

	return destinationCells;
}

CellUnorderedSet BoundsMoveGenerator::generateQueenMoves(const Cell& currentCell, Side side) const {
	CellUnorderedSet bishopMoves = generateBishopMoves(currentCell, side);
	CellUnorderedSet rookMoves = generateRookMoves(currentCell, side);

	bishopMoves.insert(rookMoves.begin(), rookMoves.end());

	return bishopMoves;
}

CellUnorderedSet BoundsMoveGenerator::generatePawnMoves(const Cell& currentCell, Side side) const {
	CellUnorderedSet destinationCells;
	Cell forwardMove = currentCell;

	if (side == Side::WHITE) {
		forwardMove.moveTop();
	} else {
		forwardMove.moveDown();
	}

	destinationCells.insert(forwardMove);

	return destinationCells;
}

bool BoundsMoveGenerator::isSameSidePiece(const Cell& cell, Side side) const {
	return board.getPieceOnCell(cell).side == side;
}

bool BoundsMoveGenerator::isValidMove(const Cell& cell, Side side) const {
	return board.isInBounds(cell) &&
			(board.isEmptyCell(cell) ||
			(!board.isEmptyCell(cell) && !isSameSidePiece(cell, side)));
}

#include "BoardBoundsPieceMoveGenerator.h"

#include <iostream>

#include "examples/chess/chess-engine/ChessBoard.h"

BoardBoundsPieceMoveGenerator::BoardBoundsPieceMoveGenerator(
		ChessBoard &chessBoard) :
		board(chessBoard) {
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generatePieceMoves(
		const Piece &piece, const Cell &source) const {
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
	case Rank::KING:
		moves = generateKingMoves(source, piece.side);
		break;
	default:
		break;
	}

	CellUnorderedSet movesInBounds;

	for (const Cell &c : moves) {
		if (board.isInBounds(c)) {
			movesInBounds.insert(c);
		}
	}

	return movesInBounds;
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generateKnightMoves(
		const Cell &knightPosition) const {
	CellUnorderedSet m;
	m.reserve(8);

	m.insert(Cell { knightPosition.row - 2, knightPosition.col + 1 });
	m.insert(Cell { knightPosition.row - 2, knightPosition.col - 1 });

	m.insert(Cell { knightPosition.row + 2, knightPosition.col + 1 });
	m.insert(Cell { knightPosition.row + 2, knightPosition.col - 1 });

	m.insert(Cell { knightPosition.row - 1, knightPosition.col - 2 });
	m.insert(Cell { knightPosition.row + 1, knightPosition.col - 2 });

	m.insert(Cell { knightPosition.row - 1, knightPosition.col + 2 });
	m.insert(Cell { knightPosition.row + 1, knightPosition.col + 2 });

	return m;
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generateRookMoves(
		const Cell &currentCell, Side side) const {
	CellUnorderedSet destinationCells;

	/* Go top */
	Cell cellGoingTop = currentCell;
	cellGoingTop.moveTop();

	while (isValidMove(cellGoingTop, side)) {
		destinationCells.insert(cellGoingTop);
		if (board.isEnemyCell(cellGoingTop, side))
			break;
		cellGoingTop.moveTop();
	}

	/* Go right */
	Cell cellGoingRight = currentCell;
	cellGoingRight.moveRight();

	while (isValidMove(cellGoingRight, side)) {
		destinationCells.insert(cellGoingRight);
		if (board.isEnemyCell(cellGoingRight, side))
			break;
		cellGoingRight.moveRight();
	}

	/* Go down */
	Cell cellGoingDown = currentCell;
	cellGoingDown.moveDown();

	while (isValidMove(cellGoingDown, side)) {
		destinationCells.insert(cellGoingDown);
		if (board.isEnemyCell(cellGoingDown, side))
			break;
		cellGoingDown.moveDown();
	}

	/* Go left */
	Cell cellGoingLeft = currentCell;
	cellGoingLeft.moveLeft();

	while (isValidMove(cellGoingLeft, side)) {
		destinationCells.insert(cellGoingLeft);
		if (board.isEnemyCell(cellGoingLeft, side))
			break;
		cellGoingLeft.moveLeft();
	}

	return destinationCells;
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generateBishopMoves(
		const Cell &currentCell, Side side) const {
	CellUnorderedSet destinationCells;

	/* Go top-left diagonal */
	Cell cellGoingTopLeft = currentCell;
	cellGoingTopLeft.moveTop().moveLeft();

	while (isValidMove(cellGoingTopLeft, side)) {
		destinationCells.insert(cellGoingTopLeft);
		if (board.isEnemyCell(cellGoingTopLeft, side))
			break;
		cellGoingTopLeft.moveTop().moveLeft();
	}

	/* Go top-right */
	Cell cellGoingTopRight = currentCell;
	cellGoingTopRight.moveTop().moveRight();

	while (isValidMove(cellGoingTopRight, side)) {
		destinationCells.insert(cellGoingTopRight);
		if (board.isEnemyCell(cellGoingTopRight, side))
			break;
		cellGoingTopRight.moveRight().moveTop();
	}

	/* Go down-right */
	Cell cellGoingDownRight = currentCell;
	cellGoingDownRight.moveDown().moveRight();

	while (isValidMove(cellGoingDownRight, side)) {
		destinationCells.insert(cellGoingDownRight);
		if (board.isEnemyCell(cellGoingDownRight, side))
			break;
		cellGoingDownRight.moveDown().moveRight();
	}

	/* Go down-left */
	Cell cellGoingDownLeft = currentCell;
	cellGoingDownLeft.moveLeft().moveDown();

	while (isValidMove(cellGoingDownLeft, side)) {
		destinationCells.insert(cellGoingDownLeft);
		if (board.isEnemyCell(cellGoingDownLeft, side))
			break;
		cellGoingDownLeft.moveLeft().moveDown();
	}

	return destinationCells;
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generateQueenMoves(
		const Cell &currentCell, Side side) const {
	CellUnorderedSet bishopMoves = generateBishopMoves(currentCell, side);
	CellUnorderedSet rookMoves = generateRookMoves(currentCell, side);

	bishopMoves.insert(rookMoves.begin(), rookMoves.end());

	return bishopMoves;
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generatePawnMoves(
		const Cell &currentCell, Side side) const {
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

bool BoardBoundsPieceMoveGenerator::isValidMove(const Cell &cell,
		Side side) const {
	return board.isInBounds(cell) && board.isValidTarget(cell, side);
}

CellUnorderedSet BoardBoundsPieceMoveGenerator::generateKingMoves(
		const Cell &pos, [[maybe_unused]]Side side) const {
	CellUnorderedSet m;

	m.insert(Cell { pos.row - 1, pos.col - 1 });
	m.insert(Cell { pos.row - 1, pos.col });

	m.insert(Cell { pos.row - 1, pos.col + 1 });
	m.insert(Cell { pos.row, pos.col + 1 });

	m.insert(Cell { pos.row + 1, pos.col + 1 });
	m.insert(Cell { pos.row + 1, pos.col });

	m.insert(Cell { pos.row + 1, pos.col - 1 });
	m.insert(Cell { pos.row, pos.col - 1 });

	return m;
}

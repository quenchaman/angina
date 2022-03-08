#include "PieceMoveGenerator.h"

#include "examples/chess/chess-engine/ChessBoard.h"

PieceMoveGenerator::PieceMoveGenerator(ChessBoard& chessBoard): board(chessBoard) {}

std::vector<Cell> PieceMoveGenerator::generatePieceMoves(Piece piece, Cell source) const {
	std::vector<Cell> moves;

	switch (piece.rank) {
		case Rank::KNIGHT:
			moves = generateKnightMoves(source);
			break;
		case Rank::ROOK:
			moves = generateRookMoves(source);
			break;
		case Rank::BISHOP:
			moves = generateBishopMoves(source);
			break;
		case Rank::PAWN:
			moves = generatePawnMoves(source, piece.side);
			break;
		case Rank::QUEEN:
			moves = generateQueenMoves(source);
			break;
		default:
			break;
	}

	return moves;
}

std::vector<Cell> PieceMoveGenerator::generateKnightMoves(Cell& knightPosition) const {
	std::vector<Cell> m;
	m.reserve(8);

	m.push_back(Cell{knightPosition.row - 2, knightPosition.col + 1});
	m.push_back(Cell{knightPosition.row - 2, knightPosition.col - 1});

	m.push_back(Cell{knightPosition.row + 2, knightPosition.col + 1});
	m.push_back(Cell{knightPosition.row + 2, knightPosition.col - 1});

	m.push_back(Cell{knightPosition.row - 1, knightPosition.col - 2});
	m.push_back(Cell{knightPosition.row + 1, knightPosition.col - 2});

	m.push_back(Cell{knightPosition.row - 1, knightPosition.col + 2});
	m.push_back(Cell{knightPosition.row + 1, knightPosition.col + 2});

	return m;
}

std::vector<Cell> PieceMoveGenerator::generateRookMoves(Cell& currentCell) const {
	std::vector<Cell> destinationCells;

	/* Go top */
	Cell cellGoingTop = currentCell;

	while (board.isInBounds(cellGoingTop) && !board.isFriendlyCell(cellGoingTop)) {
		destinationCells.push_back(cellGoingTop);
		cellGoingTop.moveTop();
	}

	/* Go right */
	Cell cellGoingRight = currentCell;

	while (board.isInBounds(cellGoingRight) && !board.isFriendlyCell(cellGoingRight)) {
		destinationCells.push_back(cellGoingRight);
		cellGoingRight.moveRight();
	}

	/* Go down */
	Cell cellGoingDown = currentCell;

	while (board.isInBounds(cellGoingDown) && !board.isFriendlyCell(cellGoingDown)) {
		destinationCells.push_back(cellGoingDown);
		cellGoingDown.moveDown();
	}

	/* Go left */
	Cell cellGoingLeft = currentCell;

	while (board.isInBounds(cellGoingLeft) && !board.isFriendlyCell(cellGoingLeft)) {
		destinationCells.push_back(cellGoingLeft);
		cellGoingDown.moveLeft();
	}

	return destinationCells;
}

std::vector<Cell> PieceMoveGenerator::generateBishopMoves(Cell& currentCell) const {
	std::vector<Cell> destinationCells;

	/* Go top-left diagonal */
	Cell cellGoingTopLeft = currentCell;

	while (board.isInBounds(cellGoingTopLeft) && !board.isFriendlyCell(cellGoingTopLeft)) {
		destinationCells.push_back(cellGoingTopLeft);
		cellGoingTopLeft.moveTop();
		cellGoingTopLeft.moveLeft();
	}

	/* Go top-right */
	Cell cellGoingTopRight = currentCell;

	while (board.isInBounds(cellGoingTopRight) && !board.isFriendlyCell(cellGoingTopRight)) {
		destinationCells.push_back(cellGoingTopRight);
		cellGoingTopRight.moveRight();
		cellGoingTopRight.moveTop();
	}

	/* Go down-right */
	Cell cellGoingDownRight = currentCell;

	while (board.isInBounds(cellGoingDownRight) && !board.isFriendlyCell(cellGoingDownRight)) {
		destinationCells.push_back(cellGoingDownRight);
		cellGoingDownRight.moveDown();
		cellGoingDownRight.moveRight();
	}

	/* Go down-left */
	Cell cellGoingDownLeft = currentCell;

	while (board.isInBounds(cellGoingDownLeft) && !board.isFriendlyCell(cellGoingDownLeft)) {
		destinationCells.push_back(cellGoingDownLeft);
		cellGoingDownLeft.moveLeft();
		cellGoingDownLeft.moveDown();
	}

	return destinationCells;
}

std::vector<Cell> PieceMoveGenerator::generateQueenMoves(Cell& currentCell) const {
	std::vector<Cell> bishopMoves = generateBishopMoves(currentCell);
	std::vector<Cell> rookMoves = generateRookMoves(currentCell);

	bishopMoves.insert(bishopMoves.end(), rookMoves.begin(), rookMoves.end());

	return bishopMoves;
}

std::vector<Cell> PieceMoveGenerator::generatePawnMoves(Cell& currentCell, Side side) const {
	std::vector<Cell> destinationCells;

	Cell forwardMove = currentCell;

	if (side == Side::WHITE) {
		forwardMove.moveTop();
	} else {
		forwardMove.moveDown();
	}

	destinationCells.push_back(forwardMove);

	return destinationCells;
}

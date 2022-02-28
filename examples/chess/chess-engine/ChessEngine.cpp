#include "ChessEngine.h"

#include <cstdint>

ChessEngine::ChessEngine() {
	setBoard();
}

void ChessEngine::setBoard() {
	const int32_t blackPawnRow = 1;
	const int32_t whitePawnRow = 6;

	for (int32_t col = 0; col < BOARD_SIZE; col++) {
		board[Cell { blackPawnRow, col }] = Piece { Rank::PAWN, Side::BLACK };
		board[Cell { whitePawnRow, col }] = Piece { Rank::PAWN, Side::WHITE };
	}

	board[Cell {0, 0}] = Piece { Rank::ROOK, Side::BLACK };
	board[Cell {0, 1}] = Piece { Rank::BISHOP, Side::BLACK };
	board[Cell {0, 2}] = Piece { Rank::KNIGHT, Side::BLACK };
	board[Cell {0, 3}] = Piece { Rank::QUEEN, Side::BLACK };
	board[Cell {0, 4}] = Piece { Rank::KING, Side::BLACK };
	board[Cell {0, 5}] = Piece { Rank::KNIGHT, Side::BLACK };
	board[Cell {0, 6}] = Piece { Rank::BISHOP, Side::BLACK };
	board[Cell {0, 7}] = Piece { Rank::ROOK, Side::BLACK };

	board[Cell {7, 0}] = Piece { Rank::ROOK, Side::WHITE };
	board[Cell {7, 1}] = Piece { Rank::BISHOP, Side::WHITE };
	board[Cell {7, 2}] = Piece { Rank::KNIGHT, Side::WHITE };
	board[Cell {7, 3}] = Piece { Rank::QUEEN, Side::WHITE };
	board[Cell {7, 4}] = Piece { Rank::KING, Side::WHITE };
	board[Cell {7, 5}] = Piece { Rank::KNIGHT, Side::WHITE };
	board[Cell {7, 6}] = Piece { Rank::BISHOP, Side::WHITE };
	board[Cell {7, 7}] = Piece { Rank::ROOK, Side::WHITE };
}

bool ChessEngine::makeMove(const Cell& source, const Cell& destination) {
	if (!isValidMove(source, destination)) {
		return false;
	}

	if (!isAllowedMove(source, destination)) {
		return false;
	}

	movePiece(source, destination);

	return true;
}

void ChessEngine::movePiece(const Cell& source, const Cell& destination) {
	Piece sourcePiece = board[source];
	board.erase(source);
	board[destination] = sourcePiece;
}

bool ChessEngine::isValidMove(const Cell& source, const Cell& destination) const {
	bool inBounds = isInBounds(source) && isInBounds(destination);

	if (!inBounds || isEmptyCell(source)) {
		return false;
	}

	bool sourcePieceIsOnMove = board.at(source).side == currentSide;
	bool friendyFire = !isEmptyCell(destination) && isFriendlyCell(destination);

	return sourcePieceIsOnMove && !friendyFire;
}

bool ChessEngine::isAllowedMove(const Cell& source, const Cell& destination) const {
	Piece sourcePiece = board.at(source);
	std::vector<Cell> allowedMoves = generatePieceMoves(sourcePiece, source);

	for (Cell& dest : allowedMoves) {
		if (dest == destination) {
			return true;
		}
	}

	return false;
}

bool ChessEngine::isInBounds(const Cell& cell) const {
	return cell.row >= 0 && cell.row < BOARD_SIZE && cell.col >= 0 && cell.row < BOARD_SIZE;
}

bool ChessEngine::isEmptyCell(const Cell& cell) const {
	return board.find(cell) == board.end();
}

bool ChessEngine::isFriendlyCell(const Cell& cell) const {
	return board.at(cell).side == currentSide;
}

std::vector<Cell> ChessEngine::generatePieceMoves(Piece piece, Cell source) const {
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

std::vector<Cell> ChessEngine::generateKnightMoves(Cell& knightPosition) const {
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

std::vector<Cell> ChessEngine::generateRookMoves(Cell& currentCell) const {
	std::vector<Cell> destinationCells;

	/* Go top */
	Cell cellGoingTop = currentCell;

	while (isInBounds(cellGoingTop) && !isFriendlyCell(cellGoingTop)) {
		destinationCells.push_back(cellGoingTop);
		cellGoingTop.moveTop();
	}

	/* Go right */
	Cell cellGoingRight = currentCell;

	while (isInBounds(cellGoingRight) && !isFriendlyCell(cellGoingRight)) {
		destinationCells.push_back(cellGoingRight);
		cellGoingRight.moveRight();
	}

	/* Go down */
	Cell cellGoingDown = currentCell;

	while (isInBounds(cellGoingDown) && !isFriendlyCell(cellGoingDown)) {
		destinationCells.push_back(cellGoingDown);
		cellGoingDown.moveDown();
	}

	/* Go left */
	Cell cellGoingLeft = currentCell;

	while (isInBounds(cellGoingLeft) && !isFriendlyCell(cellGoingLeft)) {
		destinationCells.push_back(cellGoingLeft);
		cellGoingDown.moveLeft();
	}

	return destinationCells;
}

std::vector<Cell> ChessEngine::generateBishopMoves(Cell& currentCell) const {
	std::vector<Cell> destinationCells;

	/* Go top-left diagonal */
	Cell cellGoingTopLeft = currentCell;

	while (isInBounds(cellGoingTopLeft) && !isFriendlyCell(cellGoingTopLeft)) {
		destinationCells.push_back(cellGoingTopLeft);
		cellGoingTopLeft.moveTop();
		cellGoingTopLeft.moveLeft();
	}

	/* Go top-right */
	Cell cellGoingTopRight = currentCell;

	while (isInBounds(cellGoingTopRight) && !isFriendlyCell(cellGoingTopRight)) {
		destinationCells.push_back(cellGoingTopRight);
		cellGoingTopRight.moveRight();
		cellGoingTopRight.moveTop();
	}

	/* Go down-right */
	Cell cellGoingDownRight = currentCell;

	while (isInBounds(cellGoingDownRight) && !isFriendlyCell(cellGoingDownRight)) {
		destinationCells.push_back(cellGoingDownRight);
		cellGoingDownRight.moveDown();
		cellGoingDownRight.moveRight();
	}

	/* Go down-left */
	Cell cellGoingDownLeft = currentCell;

	while (isInBounds(cellGoingDownLeft) && !isFriendlyCell(cellGoingDownLeft)) {
		destinationCells.push_back(cellGoingDownLeft);
		cellGoingDownLeft.moveLeft();
		cellGoingDownLeft.moveDown();
	}

	return destinationCells;
}

std::vector<Cell> ChessEngine::generateQueenMoves(Cell& currentCell) const {
	std::vector<Cell> bishopMoves = generateBishopMoves(currentCell);
	std::vector<Cell> rookMoves = generateRookMoves(currentCell);

	bishopMoves.insert(bishopMoves.end(), rookMoves.begin(), rookMoves.end());

	return bishopMoves;
}

std::vector<Cell> ChessEngine::generatePawnMoves(Cell& currentCell, Side side) const {
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

/* AI API */
std::vector<Move> ChessEngine::calculateAllAvailableMoves(Side side) const {
	std::vector<Move> allMoves;

	for (auto const& [cell, piece] : board) {
		if (piece.side == side) {
			std::vector<Cell> currentPieceMoves = generatePieceMoves(piece, cell);

			for (Cell& dest : currentPieceMoves) {
				if (isValidMove(cell, dest)) {
					allMoves.push_back(Move{cell, dest});
				}
			}
		}
	}

	return allMoves;
}

std::ostream& operator<<(std::ostream& os, const ChessEngine& chessEngine) {
	for (auto const& [cell, piece] : chessEngine.board) {
		os << "At cell: " << cell << " is piece: " << piece.rank << std::endl;
	}

	return os;
}

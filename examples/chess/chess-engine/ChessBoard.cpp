#include <cstdint>
#include "ChessBoard.h"

ChessBoard::ChessBoard() {
	setBoard();
}

void ChessBoard::setBoard() {
	const int32_t blackPawnRow = 1;
	const int32_t whitePawnRow = 6;

	for (int32_t col = 0; col < BOARD_SIZE; col++) {
		board[Cell { blackPawnRow, col }] = Piece::BLACK_PAWN;
		board[Cell { whitePawnRow, col }] = Piece::WHITE_PAWN;
	}

	board[Cell {0, 0}] = Piece::BLACK_ROOK;
	board[Cell {0, 1}] = Piece::BLACK_BISHOP;
	board[Cell {0, 2}] = Piece::BLACK_KNIGHT;
	board[Cell {0, 3}] = Piece::BLACK_QUEEN;
	board[Cell {0, 4}] = Piece::BLACK_KING;
	board[Cell {0, 5}] = Piece::BLACK_KNIGHT;
	board[Cell {0, 6}] = Piece::BLACK_BISHOP;
	board[Cell {0, 7}] = Piece::BLACK_ROOK;

	board[Cell {7, 0}] = Piece::WHITE_ROOK;
	board[Cell {7, 1}] = Piece::WHITE_BISHOP;
	board[Cell {7, 2}] = Piece::WHITE_KNIGHT;
	board[Cell {7, 3}] = Piece::WHITE_QUEEN;
	board[Cell {7, 4}] = Piece::WHITE_KING;
	board[Cell {7, 5}] = Piece::WHITE_KNIGHT;
	board[Cell {7, 6}] = Piece::WHITE_BISHOP;
	board[Cell {7, 7}] = Piece::WHITE_ROOK;

	for (auto& [cell, piece] : board) {
		piece.move(cell);
	}
}

bool ChessBoard::makeMove(const Cell& source, const Cell& destination) {
	if (!isValidMove(source, destination) || !isAllowedMove(source, destination)) {
		return false;
	}

	std::cout << "Attemptingg to move piece " << destination << std::endl;

	movePiece(source, destination);

	return true;
}

void ChessBoard::movePiece(const Cell& source, const Cell& destination) {
	Piece sourcePiece = board[source];
	board.erase(source);
	board[destination] = sourcePiece;
}

bool ChessBoard::isValidMove(const Cell& source, const Cell& destination) const {
	bool inBounds = isInBounds(source) && isInBounds(destination);

	if (!inBounds || isEmptyCell(source)) {
		return false;
	}

	bool sourcePieceIsOnMove = board.at(source).side == currentSide;
	bool friendyFire = !isEmptyCell(destination) && isFriendlyCell(destination);

	return sourcePieceIsOnMove && !friendyFire;
}

bool ChessBoard::isAllowedMove(const Cell& source, const Cell& destination) const {
	Piece sourcePiece = board.at(source);
	std::vector<Cell> allowedMoves = generatePieceMoves(sourcePiece, source);

	for (Cell& dest : allowedMoves) {
		if (dest == destination) {
			return true;
		}
	}

	return false;
}

Side ChessBoard::switchSide() {
	if (currentSide == Side::WHITE) {
		currentSide = Side::BLACK;
	} else {
		currentSide = Side::WHITE;
	}

	return currentSide;
}

bool ChessBoard::isInBounds(const Cell& cell) const {
	return cell.row >= 0 && cell.row < BOARD_SIZE && cell.col >= 0 && cell.row < BOARD_SIZE;
}

bool ChessBoard::isEmptyCell(const Cell& cell) const {
	return board.find(cell) == board.end();
}

bool ChessBoard::isFriendlyCell(const Cell& cell) const {
	return board.at(cell).side == currentSide;
}

std::vector<Cell> ChessBoard::generatePieceMoves(Piece piece, Cell source) const {
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

std::vector<Cell> ChessBoard::generateKnightMoves(Cell& knightPosition) const {
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

std::vector<Cell> ChessBoard::generateRookMoves(Cell& currentCell) const {
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

std::vector<Cell> ChessBoard::generateBishopMoves(Cell& currentCell) const {
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

std::vector<Cell> ChessBoard::generateQueenMoves(Cell& currentCell) const {
	std::vector<Cell> bishopMoves = generateBishopMoves(currentCell);
	std::vector<Cell> rookMoves = generateRookMoves(currentCell);

	bishopMoves.insert(bishopMoves.end(), rookMoves.begin(), rookMoves.end());

	return bishopMoves;
}

std::vector<Cell> ChessBoard::generatePawnMoves(Cell& currentCell, Side side) const {
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

std::vector<Move> ChessBoard::generateValidPieceMoves(const Piece& piece, const Cell& cell) const {
	std::vector<Move> moves;

	std::vector<Cell> currentPieceMoves = generatePieceMoves(piece, cell);

	for (Cell& dest : currentPieceMoves) {
		if (isValidMove(cell, dest)) {
			double score = scoreMove(dest);
			moves.push_back(Move{cell, dest, score});
		}
	}

	return moves;
}

std::vector<Move> ChessBoard::calculateMovesForPiece(const Cell& source) const {
	std::vector<Move> moves;

	if (board.find(source) != board.end()) {
		moves = generateValidPieceMoves(board.at(source), source);
	}

	return moves;
}

/* AI API */
std::vector<Move> ChessBoard::calculateAllAvailableMoves(Side side) const {
	std::vector<Move> allMoves;

	for (auto const& [cell, piece] : board) {
		if (piece.side == side) {
			std::vector<Move> currentValidPieceMoves = generateValidPieceMoves(piece, cell);

			allMoves.insert(allMoves.end(), currentValidPieceMoves.begin(), currentValidPieceMoves.end());
		}
	}

	return allMoves;
}

double ChessBoard::scoreMove(const Cell& destination) const {
	if (board.find(destination) != board.end()) {
		return 1;
	}

	return 0;
}

const Piece& ChessBoard::getPieceOnCell(const Cell& source) const {
	return board.at(source);
}

const CellToPieceLookup& ChessBoard::getPiecePositions() const {
	return board;
}

std::ostream& operator<<(std::ostream& os, const ChessBoard& ChessBoard) {
	for (auto const& [cell, piece] : ChessBoard.board) {
		os << "At cell: " << cell << " is piece: " << piece.rank << std::endl;
	}

	return os;
}

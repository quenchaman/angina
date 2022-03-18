#include "ChessBoard.h"

#include <cstdint>
#include <unordered_set>

#include "BoundsMoveGenerator.h"
#include "examples/chess/GameConfig.h"

ChessBoard::ChessBoard() {
	setInitialPieceFormation();
}

void ChessBoard::setInitialPieceFormation() {
	const int32_t blackPawnRow = 1;
	const int32_t whitePawnRow = 6;

	for (int32_t col = 0; col < GameConfig::BOARD_SIZE; col++) {
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
}

void ChessBoard::movePiece(const Cell& source, const Cell& destination) {
	Piece* sourcePiece = &board.at(source);
	board.erase(source);
	board[destination] = *sourcePiece;
}

bool ChessBoard::isInBounds(const Cell& cell) const {
	return cell.row >= 0 && cell.row < GameConfig::BOARD_SIZE && cell.col >= 0 && cell.col < GameConfig::BOARD_SIZE;
}

bool ChessBoard::isEmptyCell(const Cell& cell) const {
	return board.find(cell) == board.end();
}

const Piece& ChessBoard::getPieceOnCell(const Cell& source) const {
	return board.at(source);
}

const CellToPieceLookup& ChessBoard::getPiecePositions() {
	return board;
}

std::ostream& operator<<(std::ostream& os, const ChessBoard& ChessBoard) {
	for (auto const& [cell, piece] : ChessBoard.board) {
		os << "At cell: " << cell << " is piece: " << piece.rank << std::endl;
	}

	return os;
}

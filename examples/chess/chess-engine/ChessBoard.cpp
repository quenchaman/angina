#include "ChessBoard.h"

#include <cstdint>
#include <unordered_set>

#include "examples/chess/chess-engine/PieceMoveGenerator.h"

#include "examples/chess/GameConfig.h"

ChessBoard::ChessBoard(): moveGen(PieceMoveGenerator(*this)) {
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

bool ChessBoard::makeMove(const Cell& source, const Cell& destination) {
	if (!isPossibleMove(source, destination) || !isValidPieceMove(source, destination)) {
		return false;
	}

	movePiece(source, destination);
	switchSide();

	return true;
}

void ChessBoard::movePiece(const Cell& source, const Cell& destination) {
	Piece* sourcePiece = &board.at(source);
	board.erase(source);
	board[destination] = *sourcePiece;
}

bool ChessBoard::isPossibleMove(const Cell& source, const Cell& destination) const {
	bool inBounds = isInBounds(source) && isInBounds(destination);

	if (!inBounds || isEmptyCell(source)) {
		return false;
	}

	bool sourcePieceIsOnMove = board.at(source).side == currentSide;
	bool friendyFire = !isEmptyCell(destination) && isOccupiedBySameSidePiece(destination);

	return sourcePieceIsOnMove && !friendyFire;
}

bool ChessBoard::isValidPieceMove(const Cell& source, const Cell& destination) const {
	CellUnorderedSet allowedMoves = moveGen.generatePieceMoves(getPieceOnCell(source), source);

	return allowedMoves.find(destination) != allowedMoves.end();
}

Side ChessBoard::switchSide() {
	return currentSide = currentSide == Side::WHITE ? Side::BLACK : Side::WHITE;
}

bool ChessBoard::isInBounds(const Cell& cell) const {
	return cell.row >= 0 && cell.row < GameConfig::BOARD_SIZE && cell.col >= 0 && cell.col < GameConfig::BOARD_SIZE;
}

bool ChessBoard::isEmptyCell(const Cell& cell) const {
	return board.find(cell) == board.end();
}

bool ChessBoard::isOccupiedBySameSidePiece(const Cell& cell) const {
	return !isEmptyCell(cell) && board.at(cell).side == currentSide;
}

std::vector<Move> ChessBoard::generateValidPieceMoves(const Piece& piece, const Cell& cell) const {
	std::vector<Move> moves;
	CellUnorderedSet currentPieceMoves = moveGen.generatePieceMoves(piece, cell);

	for (const Cell& dest : currentPieceMoves) {
		if (isPossibleMove(cell, dest)) {

			double score = scoreMove(dest);
			moves.push_back(Move{cell, dest, score});
		}
	}

	return moves;
}

/* AI API */
std::vector<Move> ChessBoard::calculateAllAvailableMoves(Side side) const {
	std::vector<Move> allMoves;

//	In chess, if a "node" is considered to be a legal position,
//	the average branching factor has been said to be about 35,[1][2]
//	and a statistical analysis of over 2.5 million games revealed an average of 31.[3]
//	This means that, on average, a player has about 31 to 35 legal moves at their disposal at each turn.
//	By comparison, the average branching factor for the game Go is 250.[1]
	allMoves.reserve(31);

	for (auto const& [cell, piece] : board) {
		if (piece.side == side) {
			std::vector<Move> currentValidPieceMoves = generateValidPieceMoves(piece, cell);

			allMoves.insert(allMoves.end(), currentValidPieceMoves.begin(), currentValidPieceMoves.end());
		}
	}

	return allMoves;
}

double ChessBoard::scoreMove(const Cell& destination) const {
	if (!isEmptyCell(destination)) {
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

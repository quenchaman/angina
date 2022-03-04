#include "ChessEngine.h"

ChessEngine::ChessEngine() {
	board.setBoard();
}

ChessEngine::~ChessEngine() {
}

void ChessEngine::selectPiece(const Cell& source) {
	if (state != ChessState::WHITE_PLAYER) {
		return;
	}

	selectedCell = source;
	setState(ChessState::WHITE_PIECE_SELECTED);
}

void ChessEngine::movePiece(const Cell& destination) {
	if (state != ChessState::WHITE_PIECE_SELECTED) {
		return;
	}

	board.makeMove(selectedCell, destination);
	setState(ChessState::COMPUTER_MOVE);
}

void ChessEngine::setState(ChessState newState) {
	state = newState;
}

bool ChessEngine::isCellSelected() const {
	return selectedCell != Cell::UNDEFINED;
}

const Cell ChessEngine::getCellOfPiece(const Piece& piece) const {
	return board.getCellOfPiece(piece);
}

const CellToPieceLookup& ChessEngine::getPieces() const {
	return board.getPiecePositions();
}

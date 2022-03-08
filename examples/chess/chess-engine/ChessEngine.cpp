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
	notify(selectedCell, destination);
	setState(ChessState::COMPUTER_MOVE);
}

void ChessEngine::setState(ChessState newState) {
	state = newState;
}

bool ChessEngine::isCellSelected() const {
	return selectedCell != Cell::UNDEFINED;
}

const CellToPieceLookup& ChessEngine::getPieces() const {
	return board.getPiecePositions();
}

void ChessEngine::subscribe(MoveEventCallback callback) {
	subscribers.push_back(callback);
}

void ChessEngine::notify(const Cell& source, const Cell& destination) const {
	for (auto& subscriber : subscribers) {
		subscriber(source, destination);
	}
}

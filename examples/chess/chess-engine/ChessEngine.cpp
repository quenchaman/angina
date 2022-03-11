#include "ChessEngine.h"

#include "examples/chess/chess-engine/ChessMoveManager.h"

ChessEngine::ChessEngine(ChessBoard& chessBoard, ChessMoveManager& moveMng):
	moveManager(moveMng),
	board(chessBoard),
	selectedCell(Cell::UNDEFINED),
	state(ChessState::HUMAN_SELECT_PIECE), // This should be checked based on player type.
	currentSide(Side::WHITE),
	whitePlayerType(PlayerType::HUMAN),
	blackPlayerType(PlayerType::COMPUTER) {}


bool ChessEngine::selectCell(const Cell& cell) {
	if (state != ChessState::HUMAN_SELECT_PIECE || board.isEmptyCell(cell)) {
		return false;
	}

	Piece piece = board.getPieceOnCell(cell);

	if (!isSelectedPieceOnTurn(piece)) {
		return false;
	}

	selectedCell = cell;
	setState(ChessState::HUMAN_PIECE_SELECTED);

	return true;
}

bool ChessEngine::movePiece(const Cell& destination) {
	if (state != ChessState::HUMAN_PIECE_SELECTED) {
		return false;
	}

	bool moveOK = moveManager.movePiece(selectedCell, destination);

	if (moveOK) {
		setState(ChessState::COMPUTER_MOVE);
	}

	return moveOK;
}

bool ChessEngine::makeComputerMove() {
	if (state != ChessState::COMPUTER_MOVE) {
		return false;
	}

	return moveManager.getAIMove(currentSide);
}

bool ChessEngine::isSelectedPieceOnTurn(const Piece& piece) const {
	return piece.side == currentSide;
}

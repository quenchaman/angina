#include "ChessEngine.h"

#include "examples/chess/chess-engine/ChessMoveManager.h"

ChessEngine::ChessEngine(ChessBoard& chessBoard, ChessMoveManager& moveMng):
	moveManager(moveMng),
	board(chessBoard),
	selectedCell(Cell::UNDEFINED),
	state(ChessState::NO_OP),
	currentSide(Side::WHITE),
	whitePlayerType(PlayerType::HUMAN),
	blackPlayerType(PlayerType::HUMAN) {

	if (whitePlayerType == PlayerType::HUMAN) {
		state = ChessState::HUMAN_SELECT_PIECE;
	} else {
		state = ChessState::COMPUTER_MOVE;
	}

	sideToPlayerType[Side::WHITE] = whitePlayerType;
	sideToPlayerType[Side::BLACK] = blackPlayerType;
}

bool ChessEngine::selectCell(const Cell& cell) {
	if (state != ChessState::HUMAN_SELECT_PIECE || board.isEmptyCell(cell)) {
		return false;
	}

	Piece piece = board.getPieceOnCell(cell);

	std::cout << "The current side is " << currentSide << std::endl;
	std::cout << "1 Selected piece " << piece.rank << " and side is " << piece.side << std::endl;

	if (!isSelectedPieceOnTurn(piece)) {
		return false;
	}

	std::cout << "2 Selected piece " << piece.rank << std::endl;

	selectedCell = cell;
	setState(ChessState::HUMAN_PIECE_SELECTED);

	return true;
}

bool ChessEngine::movePiece(const Cell& destination) {
	if (state != ChessState::HUMAN_PIECE_SELECTED) {
		return false;
	}

	bool moveOK = moveManager.movePiece(selectedCell, destination);

	std::cout << "Is the move ok " << moveOK << std::endl;

	if (moveOK) {
		switchSide();
		setState(getNextState());
	} else {
		setState(ChessState::HUMAN_SELECT_PIECE);
	}

	resetSelection();

	return moveOK;
}

// TODO: Improve this once we get to AI
bool ChessEngine::makeComputerMove() {
	if (state != ChessState::COMPUTER_MOVE) {
		return false;
	}

	Move aiMove = moveManager.getAIMove(currentSide);

	moveManager.movePiece(aiMove.source, aiMove.destination);

	resetSelection();
	switchSide();
	setState(getNextState());

	return true;
}

bool ChessEngine::isSelectedPieceOnTurn(const Piece& piece) const {
	return piece.side == currentSide;
}

ChessState ChessEngine::getNextState() {
	PlayerType nextPlayerType = sideToPlayerType[currentSide];

	if (nextPlayerType == PlayerType::COMPUTER) {
		return ChessState::COMPUTER_MOVE;
	} else {
		return ChessState::HUMAN_SELECT_PIECE;
	}
}

bool ChessEngine::isCellSelected() const {
	return selectedCell != Cell::UNDEFINED;
}

Side ChessEngine::switchSide() {
	Side cs = (currentSide == Side::WHITE) ? Side::BLACK : Side::WHITE;
	std::cout << "Switching side to " << cs << std::endl;
	currentSide = cs;
	return cs;
}

ChessState ChessEngine::setState(ChessState newState) {
	return state = newState;
}

void ChessEngine::resetSelection() {
	selectedCell = Cell::UNDEFINED;
}

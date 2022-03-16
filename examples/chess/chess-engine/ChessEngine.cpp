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

	const CellToPieceLookup& b = board.getPiecePositions();
	for (auto const& [cell, piece] : b) {
			std::cout << "Before the cells are " << cell << " and the address of collection is " << &b << std::endl;
		}
	bool moveOK = moveManager.movePiece(selectedCell, destination);

	const CellToPieceLookup& b2 = board.getPiecePositions();
	for (auto const& [cell, piece] : b2) {
				std::cout << "After the cells are " << cell << " and the address of collection is " << &b2 << std::endl;
			}

	std::cout << "Is the move OK? " << moveOK << std::endl;

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
	return currentSide = (currentSide == Side::WHITE) ? Side::BLACK : Side::WHITE;
}

ChessState ChessEngine::setState(ChessState newState) {
	return state = newState;
}

void ChessEngine::resetSelection() {
	selectedCell = Cell::UNDEFINED;
}

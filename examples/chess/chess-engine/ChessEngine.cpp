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

	bool moveOK = moveManager.movePiece(selectedCell, destination);

	bool isChecked = isKingAttacked();

	if (isChecked) {
		std::cout << "we are under check!" << std::endl;
		moveManager.movePiece(destination, selectedCell, true);
	}

	moveOK = moveOK && !isChecked;

	if (moveOK) {
		switchSide();
		setState(getNextState());
	} else {
		std::cout << "We should select a piece again" << std::endl;
		std::cout << "The current side is " << currentSide << std::endl;
		setState(ChessState::HUMAN_SELECT_PIECE);
	}

	resetSelection();

	return moveOK;
}

bool ChessEngine::isKingAttacked() {
	std::vector<Move> allEnemyMoves = moveManager.calculateAllAvailableMoves(getEnemySide());

	// From the 'check' logic we can safely say that we will always have a king piece on the board.
	Cell kingPosition = board.getPiecePosition(Piece{ Rank::KING, currentSide });

	std::cout << "We are checking if the king is attacked for side " << currentSide <<
			" The king position is " << kingPosition << std::endl;

	for (Move& m : allEnemyMoves) {
		if (m.destination == kingPosition) {
			std::cout << "The move that will attack the king is " << m << std::endl;
			return true;
		}
	}

	return false;
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
	Side cs = getEnemySide();
	currentSide = cs;
	return cs;
}

ChessState ChessEngine::setState(ChessState newState) {
	return state = newState;
}

void ChessEngine::resetSelection() {
	selectedCell = Cell::UNDEFINED;
}

Side ChessEngine::getEnemySide() const {
	return (currentSide == Side::WHITE) ? Side::BLACK : Side::WHITE;
}

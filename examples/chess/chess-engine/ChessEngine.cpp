#include "ChessEngine.h"

#include "examples/chess/chess-engine/ChessMoveManager.h"
#include "examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h"
#include "examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h"

ChessEngine::ChessEngine(ChessBoard &chessBoard, ChessMoveManager &moveMng,
        PlayerType whitePType, PlayerType blackPType) :
        moveManager(moveMng), board(chessBoard), selectedCell(Cell::UNDEFINED), state(
                ChessState::NO_OP), currentSide(Side::WHITE), whitePlayerType(
                whitePType), blackPlayerType(blackPType) {

    if (whitePlayerType == PlayerType::HUMAN) {
        state = ChessState::HUMAN_SELECT_PIECE;
    } else {
        state = ChessState::COMPUTER_MOVE;
    }

    sideToPlayerType[Side::WHITE] = whitePlayerType;
    sideToPlayerType[Side::BLACK] = blackPlayerType;
}

bool ChessEngine::selectCell(const Cell &cell) {
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

bool ChessEngine::movePiece(const Cell &destination) {
    if (state != ChessState::HUMAN_PIECE_SELECTED) {
        return false;
    }

    bool moveOK = isMoveAllowed(selectedCell, destination);

    if (moveOK) {
    		moveManager.movePiece(selectedCell, destination);
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
    std::vector<Move> aiMoves = moveManager.getAIMoves(currentSide);

    for (Move &move : aiMoves) {
        bool isMoveOk = isMoveAllowed(move.source, move.destination);

        if (isMoveOk) {
        	moveManager.movePiece(move.source, move.destination);
        	resetSelection();
					switchSide();
					setState(getNextState());

					return true;
        }
    }

    return false;
}

bool ChessEngine::isSelectedPieceOnTurn(const Piece &piece) const {
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

bool ChessEngine::isMoveAllowed(const Cell& src, const Cell& dst) const {
	ChessBoard& tempBoard = *(new ChessBoard(board));
	tempBoard.clearSubscribers();
	BoardBoundsPieceMoveGenerator bbpmg(tempBoard);
	FriendlyFireExcludedMoveGenerator ffemg(tempBoard, bbpmg);
	ChessMoveManager moveMng(tempBoard, ffemg);

	bool moveOK = moveMng.movePiece(src, dst);

	/**
	 * King attacked logic
	 */
	std::vector<Move> allEnemyMoves = moveMng.calculateAllAvailableMoves(
						getEnemySide());

	// From the 'check' logic we can safely say that we will always have a king piece on the board.
	Cell kingPosition = tempBoard.getPiecePosition(
					Piece { Rank::KING, currentSide });

	bool isChecked = false;

	for (Move &m : allEnemyMoves) {
			if (m.destination == kingPosition) {
					isChecked = true;
					break;
			}
	}
	/**
	 * End King attacked logic
	 */

	delete &tempBoard;
	return moveOK && !isChecked;
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

ChessState ChessEngine::getState() const {
	return state;
}

void ChessEngine::resetSelection() {
	selectedCell = Cell::UNDEFINED;
}

Side ChessEngine::getEnemySide() const {
	return (currentSide == Side::WHITE) ? Side::BLACK : Side::WHITE;
}


#include "ChessEngine.h"

#include <sstream>
#include <iostream>

#include "examples/chess/chess-engine/ChessMoveManager.h"
#include "examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h"
#include "examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h"

#include "examples/chess/GameConfig.h"

ChessEngine::ChessEngine(
    ChessBoard &chessBoard,
    ChessMoveManager &moveMng,
    ChessMoveLog &moveLog,
    PlayerType whitePType,
    PlayerType blackPType):
    moveManager(moveMng),
    board(chessBoard),
    log(moveLog),
    selectedCell(Cell::UNDEFINED),
    state(ChessState::NO_OP),
    currentSide(Side::WHITE),
    whitePlayerType(whitePType),
    blackPlayerType(blackPType)
{
	if (whitePlayerType == PlayerType::HUMAN) {
	    state = ChessState::HUMAN_SELECT_PIECE;
	} else {
		state = ChessState::COMPUTER_MOVE;
	}

	sideToPlayerType[Side::WHITE] = whitePlayerType;
	sideToPlayerType[Side::BLACK] = blackPlayerType;
}

bool ChessEngine::selectCell(const Cell &cell) {
	if (state != ChessState::HUMAN_SELECT_PIECE || board.isEmptyCell(cell) ||
        !isSelectedPieceOnTurn(board.getPieceOnCell(cell))) {

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
		log.addMove(Move { selectedCell, destination, moveManager.scoreMove(destination), currentSide });

		moveManager.movePiece(selectedCell, destination);

		switchSide();
		setState(getNextState());
	} else {
		setState(ChessState::HUMAN_SELECT_PIECE);
	}

	resetSelection();

	return moveOK;
}

bool ChessEngine::makeComputerMove() {
	for (Move &move : moveManager.getAIMoves(currentSide)) {
		if (isMoveAllowed(move.source, move.destination)) {
			log.addMove(Move { move.source, move.destination, moveManager.scoreMove(move.destination), currentSide });

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
	if (sideToPlayerType[currentSide] == PlayerType::COMPUTER) {
		return ChessState::COMPUTER_MOVE;
	} else {
		return ChessState::HUMAN_SELECT_PIECE;
	}
}

bool ChessEngine::isMoveAllowed(const Cell &src, const Cell &dst) const {
	ChessBoard &tempBoard = *(new ChessBoard(board));
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
	Cell kingPosition = tempBoard.getPiecePosition(Piece { Rank::KING, currentSide });

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
	currentSide = getEnemySide();
	return currentSide;
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

std::string ChessEngine::serialize() const {
	std::string ser;
	char br = GameConfig::SAVED_GAME_LINE_BREAK;

	/*
	 * Portion to save white and black player actor - human or computer. Also who's on turn.
	 * Ex:
	 * 0
	 * 1
	 * 0
	 * *
	 * It means that the white player is human and the black is computer. Star (*) separates from following lines.
	 * Last number means that it is white player turn.
	 */
	ser += std::to_string(whitePlayerType) + br;
	ser += std::to_string(blackPlayerType) + br;
	ser += std::to_string(currentSide) + br;
	ser += "*";
	ser += br;

	for (int32_t row = 0; row < GameConfig::BOARD_SIZE; row++) {
		for (int32_t col = 0; col < GameConfig::BOARD_SIZE; col++) {
			Cell c(row, col);

			if (!board.isEmptyCell(c)) {
				Piece p = board.getPieceOnCell(c);
				ser += p.serialize() + br;
			} else {
				ser += br;
			}
		}
	}

	return ser;
}

void ChessEngine::setPlayerType(Side side, PlayerType type) {
    if (side == Side::WHITE) {
        whitePlayerType = type;
    } else {
        blackPlayerType = type;
    }
}

void ChessEngine::deserialise(std::vector<std::string> savedGame) {
    setPlayerType(Side::WHITE, static_cast<PlayerType>(std::stoi(savedGame[0])));
    setPlayerType(Side::BLACK, static_cast<PlayerType>(std::stoi(savedGame[1])));
    currentSide = static_cast<Side>(std::stoi(savedGame[2]));

    int32_t startIdx = 4;

    for (int32_t row = 0; row < GameConfig::BOARD_SIZE; row++) {
        for (int32_t col = 0; col < GameConfig::BOARD_SIZE; col++) {
            std::string& line = savedGame[startIdx];

            if (!line.empty()) {
                std::stringstream ss(savedGame[startIdx]);

                Cell c {row, col};
                Piece p;
                ss >> p;
                board.setPiece(c, p);
            }
            startIdx++;
        }
    }
}


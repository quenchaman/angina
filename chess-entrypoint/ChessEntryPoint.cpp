//
// Created by ubuntu on 11/28/21.
//

#include "ChessEntryPoint.h"

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <string>

#include "sdl/primitives/Rect.h"
#include "sdl/engine/object/Object.h"
#include "resources/Resources.h"
#include "sdl/components/Button.h"
#include "sdl/engine/page/Page.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"
#include "chess-game/pages/LandingPage.h"
#include "chess-game/pages/ChessPage.h"
#include "chess-game/board/Board.h"
#include "chess-game/pieces/Piece.h"
#include "chess-game/board/PieceSelectionManager.h"
#include "chess-game/pieces/ValidMovesGenerator.h"
#include "config/Config.h"

void ChessEntryPoint::init() {
	navigateTo(initWelcomePage());
}

void ChessEntryPoint::update() {
	switch (state) {
		case ChessState::WHITE_PLAYER_HUMAN_MOVE:
			// TODO: Here we can reset some timer
			transitionState(ChessState::HUMAN_SELECT_PIECE);
			break;
		case ChessState::HUMAN_SELECT_PIECE:
			handleHumanSelectPieceState();
			break;
		case ChessState::HUMAN_PIECE_SELECTED:
			handlePieceSelectedState();
			break;
		case ChessState::CAPTURES:
			handleCaptures();
			break;
		case ChessState::FINISH_HUMAN_MOVE:
			handleFinishHumanMove();
			transitionState(ChessState::COMPUTER_MOVE);
			break;
		case ChessState::COMPUTER_MOVE:
			handleComputerMove();
			break;
		default:
			break;
	}
}

void ChessEntryPoint::handleLeftMouseClick(Point point) {
	clickedPoint = point;
}

void ChessEntryPoint::transitionState(ChessState newState) {
	state = newState;
}

void ChessEntryPoint::handleBtnClick(int32_t buttonId) {
	if (buttonId == ChessAssets::NEW_GAME_BUTTON) {
		navigateTo(initChessPage());
		transitionState(ChessState::WHITE_PLAYER_HUMAN_MOVE);
	} else if (buttonId == ChessAssets::QUIT_CHESS_GAME_BUTTON) {
		navigateTo(initWelcomePage());
		transitionState(ChessState::NO_OP);
	}
}

Page* ChessEntryPoint::initWelcomePage() {
	return new LandingPage(*getRenderer());
}

Page* ChessEntryPoint::initChessPage() {
	ChessPage* page = new ChessPage(*getRenderer());
	chessPage = page;
	pieceSelectionMng = new PieceSelectionManager(*page->getBoard());
	validMovesGenerator = new ValidMovesGenerator(*page->getBoard());
	return page;
}

void ChessEntryPoint::handleHumanSelectPieceState() {
	transitionState(pieceSelectionMng->selectPiece(clickedPoint));
}

void ChessEntryPoint::handlePieceSelectedState() {
	if (pieceSelectionMng->isSidePieceSelected(clickedPoint, Side::White)) {
		transitionState(pieceSelectionMng->selectPiece(clickedPoint));

		std::vector<Move> availableMoves = validMovesGenerator->generateValidMoves(pieceSelectionMng->getSelectedPiece());

		chessPage->getBoard()->setAvailableMoveCells(availableMoves);
	} else {
		Cell move = chessPage->getBoard()->getCell(clickedPoint);
		bool isItAllowedMove = chessPage->getBoard()->isAllowedMove(move);

		if (!isItAllowedMove) {
			transitionState(ChessState::FINISH_HUMAN_MOVE);
		} else {
			Piece* enemyPiece = chessPage->getBoard()->getPieceOnPosition(move);

			if (enemyPiece != nullptr) {
				transitionState(ChessState::CAPTURES);
			} else {
				chessPage->getBoard()->movePiece(pieceSelectionMng->getSelectedPiece(), move);
				transitionState(ChessState::FINISH_HUMAN_MOVE);
			}
		}
	}
}

void ChessEntryPoint::handleCaptures() {
	Cell move = chessPage->getBoard()->getCell(clickedPoint);

	chessPage->getBoard()->capturePiece(move);
	chessPage->getBoard()->movePiece(pieceSelectionMng->getSelectedPiece(), move);

	transitionState(ChessState::FINISH_HUMAN_MOVE);
}

void ChessEntryPoint::handleFinishHumanMove() {
	chessPage->getBoard()->clearAvailableMoves();
	pieceSelectionMng->clearSelection();
	unclick();
	transitionState(ChessState::HUMAN_SELECT_PIECE); // TODO: Remove this after testing
}

void ChessEntryPoint::handleComputerMove() {
	std::cout << "I....am...thinkiiinnnnnng @!#!$@ blido ba blido ba!" << std::endl;
}

void ChessEntryPoint::unclick() {
	clickedPoint = Point::UNDEFINED;
}

ChessEntryPoint::ChessEntryPoint() : Engine(Config::GAME_TITLE, Config::WINDOW_DIM) {

}

ChessEntryPoint::~ChessEntryPoint() {

}

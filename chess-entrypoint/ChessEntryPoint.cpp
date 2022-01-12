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
			// TODO: Here we calculate the allowed moves
			std::cout << "Selected piece is " << *selectedPiece << std::endl;
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
	return page;
}

void ChessEntryPoint::handleHumanSelectPieceState() {
	if (clickedPoint != Point::UNDEFINED && chessPage->getBoard()->isBoardPosition(clickedPoint)) {
		clickedBoardCell = chessPage->getBoard()->getCell(clickedPoint);
		bool isEmptyCell = chessPage->getBoard()->isEmptyCell(clickedBoardCell);

		if (!isEmptyCell) {
			Piece* pieceOnCell = chessPage->getBoard()->getPieceOnPosition(clickedBoardCell);

			if (pieceOnCell->side == Side::White) {
				std::cout << "Is the cell " << clickedBoardCell << " empty " << isEmptyCell << " and piece is " << *pieceOnCell << std::endl;

				selectedPiece = pieceOnCell;
				transitionState(ChessState::HUMAN_PIECE_SELECTED);
			}
		}
	}
}

ChessEntryPoint::ChessEntryPoint() : Engine("Test", { 800, 800 }) {

}

ChessEntryPoint::~ChessEntryPoint() {

}

#include "ChessGame.h"

#include <iostream>

#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"

#include "engine/components/buttons/RectTextButton.h"
#include "engine/config/EngineConfig.h"

#include "resources/Resources.h"

#include "examples/chess/CellUtils.h"
#include "examples/chess/GameConfig.h"
#include "examples/chess/chess-engine/PieceToObjectTranslator.h"

ChessGame::ChessGame():
	Engine(GameConfig::GAME_TITLE, GameConfig::WINDOW_DIM),
	pieceToResourceTranslator(PieceToObjectTranslator()) {}

ChessGame::~ChessGame() {
	std::cout << "ChessGame destroyed" << std::endl;
}

void ChessGame::init() {
	changeScreen(*buildLandingPage());
}

void ChessGame::update() {
	if (state == ChessState::COMPUTER_MOVE) {
		handleComputerMove();
		setState(ChessState::WHITE_PLAYER);
	}
}

void ChessGame::handleLeftMouseClick([[maybe_unused]]Point p) {
	Cell selectedCell = CellUtils::pointToCell(p, GameConfig::CELL_DIM, Point::ZERO);

	if (state == ChessState::WHITE_PLAYER && !engine.isCellSelected()) {
		engine.selectPiece(selectedCell);
		setState(ChessState::WHITE_PIECE_SELECTED);
	} else if (state == ChessState::WHITE_PIECE_SELECTED) {
		if (engine.movePiece(selectedCell)) {
			setState(ChessState::COMPUTER_MOVE);
		} else {
			setState(ChessState::WHITE_PLAYER);
		}
	}
}

void ChessGame::handleBtnClick([[maybe_unused]]int32_t idx) {
}

Widget* ChessGame::buildLandingPage() {
	Widget* landingPageWidget = new Widget(btnManager, Point::ZERO);

	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, GameConfig::WINDOW_DIM);
	landingPageWidget->put(*background);

	RectTextButton* btn = getFactory().createButton(
		GameConfig::NEW_GAME_BTN_POS,
		GameConfig::NEW_GAME_BTN_DIM,
		GameConfig::NEW_GAME_BTN_BACKGROUND_COLOR,
		GameConfig::NEW_GAME_BTN_TEXT_COLOR,
		GameConfig::NEW_GAME_BTN_TEXT,
		defaultFont,
		std::bind(&ChessGame::handleStartGameButton, this)
	);
	landingPageWidget->put(*btn);

	return landingPageWidget;
}

Widget* ChessGame::buildChessPage() {
	Widget* chessPageWidget = new Widget(btnManager, Point::ZERO);

	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, GameConfig::WINDOW_DIM);
	chessPageWidget->put(*background);

	Object* board = getFactory().createObject(Resources::board, Point::ZERO, GameConfig::BOARD_DIM);
	chessPageWidget->put(*board);

	return chessPageWidget;
}

void ChessGame::handleStartGameButton() {
	changeScreen(*buildChessPage());
	createPieceObjects();
	engine.subscribe(std::bind(&ChessGame::pieceMovedCallback, this, std::placeholders::_1, std::placeholders::_2));
}

void ChessGame::createPieceObjects() {
	const CellToPieceLookup& positions = engine.getPieces();

	for (auto const& [cell, piece] : positions) {
		Object& obj = *getFactory().createObject(
			pieceToResourceTranslator.pieceToResource[piece],
			CellUtils::cellToPoint(cell, GameConfig::CELL_DIM),
			GameConfig::CELL_DIM
		);

		rootScreen->put(obj);
		cellObject[cell] = obj;
	}
}

void ChessGame::pieceMovedCallback(const Cell& source, const Cell& destination) {
	Object& obj = cellObject[source];
	cellObject.erase(source);
	cellObject[destination] = obj;
}

void ChessGame::setState(ChessState newState) {
	state = newState;
}

void ChessGame::handleComputerMove() {
	Move bestMove = engine.getAIMove();

	engine.selectPiece(bestMove.source);
	engine.movePiece(bestMove.destination);
}

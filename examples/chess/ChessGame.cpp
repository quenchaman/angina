#include "ChessGame.h"

#include <iostream>

#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"

#include "engine/components/buttons/RectTextButton.h"
#include "engine/config/EngineConfig.h"

#include "resources/Resources.h"

#include "examples/chess/CellUtils.h"
#include "examples/chess/GameConfig.h"

ChessGame::ChessGame(): Engine(GameConfig::GAME_TITLE, GameConfig::WINDOW_DIM) {
	pieceToResource[Piece::WHITE_PAWN] = Resources::whitePawn;
	pieceToResource[Piece::WHITE_ROOK] = Resources::whiteRook;
	pieceToResource[Piece::WHITE_KNIGHT] = Resources::whiteKnight;
	pieceToResource[Piece::WHITE_BISHOP] = Resources::whiteBishop;
	pieceToResource[Piece::WHITE_QUEEN] = Resources::whiteQueen;
	pieceToResource[Piece::WHITE_KING] = Resources::whiteKing;

	pieceToResource[Piece::BLACK_PAWN] = Resources::blackPawn;
	pieceToResource[Piece::BLACK_ROOK] = Resources::blackRook;
	pieceToResource[Piece::BLACK_KNIGHT] = Resources::blackKnight;
	pieceToResource[Piece::BLACK_BISHOP] = Resources::blackBishop;
	pieceToResource[Piece::BLACK_QUEEN] = Resources::blackQueen;
	pieceToResource[Piece::BLACK_KING] = Resources::blackKing;
}

ChessGame::~ChessGame() {
	std::cout << "ChessGame destroyed" << std::endl;
}

void ChessGame::print() {
	std::cout << "Hello from print" << std::endl;
}

void ChessGame::init() {
	changeScreen(*buildLandingPage());
}

void ChessGame::update() {
}

void ChessGame::handleLeftMouseClick([[maybe_unused]]Point p) {
	Cell selectedCell = CellUtils::pointToCell(p, GameConfig::CELL_DIM, Point::ZERO);

	if (!engine.isCellSelected()) {
		engine.selectPiece(selectedCell);
	} else {
		engine.movePiece(selectedCell);
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
	initPieceToObjectConversion();
	engine.subscribe(std::bind(&ChessGame::pieceMovedCallback, this, std::placeholders::_1, std::placeholders::_2));
}

void ChessGame::initPieceToObjectConversion() {
	const CellToPieceLookup& positions = engine.getPieces();

	for (auto const& [cell, piece] : positions) {
		Object& obj = *getFactory().createObject(
			pieceToResource[piece],
			CellUtils::cellToPoint(cell, GameConfig::CELL_DIM),
			GameConfig::CELL_DIM
		);

		rootScreen->put(obj);
		cellObjectPairs.push_back(CellObjectPair{piece.cell, obj});
	}
}

void ChessGame::pieceMovedCallback(const Cell& source, const Cell& destination) {
	std::cout << "Called the callback for a piece move!" << std::endl;
	for (auto& cellObjectPair : cellObjectPairs) {
		if (cellObjectPair.cell == source) {
			cellObjectPair.cell = destination;
			cellObjectPair.object.move(CellUtils::cellToPoint(destination, GameConfig::CELL_DIM));
		}
	}
}

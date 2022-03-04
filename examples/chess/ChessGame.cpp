#include "ChessGame.h"

#include <iostream>

#include "config/Config.h"
#include "renderer/primitives/Point.h"
#include "resources/Resources.h"
#include "engine/components/buttons/RectTextButton.h"
#include "examples/chess/CellUtils.h"

ChessGame::ChessGame(): Engine("Chess", Config::WINDOW_DIM) {
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

}

void ChessGame::handleBtnClick([[maybe_unused]]int32_t idx) {

}

Widget* ChessGame::buildLandingPage() {
	Widget* landingPageWidget = new Widget(btnManager, Point::ZERO);
	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, Config::WINDOW_DIM);
	Point p = { 300, 300 };
	Dimensions dim = { 200, 70 };
	Color backgroundColor = Color::BLUE;
	Color textColor = Color::RED;
	std::string txt = "Start Game";

	RectTextButton* btn = getFactory().createButton(p, dim, backgroundColor, textColor, txt, defaultFont, std::bind(&ChessGame::handleStartGameButton, this));

	landingPageWidget->put(*background);
	landingPageWidget->put(*btn);

	return landingPageWidget;
}

Widget* ChessGame::buildChessPage() {
	Widget* chessPageWidget = new Widget(btnManager, Point::ZERO);
	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, Config::WINDOW_DIM);
	Object* board = getFactory().createObject(Resources::board, Point::ZERO, Dimensions{640, 640});

	chessPageWidget->put(*background);
	chessPageWidget->put(*board);

	return chessPageWidget;
}

void ChessGame::handleStartGameButton() {
	changeScreen(*buildChessPage());
	initPieceToObjectConversion();
}

void ChessGame::initPieceToObjectConversion() {
	const PiecePositions& positions = engine.getPieces();

	for (auto const& [cell, piece] : positions) {
		Object& obj = *getFactory().createObject(
			pieceToResource[piece],
			CellUtils::cellToPoint(cell, cellDim, Point::ZERO),
			cellDim
		);

		rootScreen->put(obj);
	}
}

#include "ChessGame.h"

#include <iostream>

#include "config/Config.h"
#include "renderer/primitives/Point.h"
#include "resources/Resources.h"
#include "engine/components/buttons/RectTextButton.h"

ChessGame::ChessGame(): Engine("Chess", Config::WINDOW_DIM) {}

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
	Object* board = getFactory().createObject(Resources::board, Point::ZERO, Dimensions{600, 600});

	chessPageWidget->put(*background);
	chessPageWidget->put(*board);

	return chessPageWidget;
}

void ChessGame::handleStartGameButton() {
	changeScreen(*buildChessPage());
}

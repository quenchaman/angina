#include "ChessGame.h"

#include <iostream>

#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"

#include "engine/components/buttons/RectTextButton.h"
#include "engine/config/EngineConfig.h"

#include "resources/Resources.h"

#include "examples/chess/CellUtils.h"
#include "examples/chess/GameConfig.h"
#include "examples/chess/chess-engine/ChessBoard.h"

/**
 * Stack-based allocation is eager. Heap based allocation is lazy.
 */
ChessGame::ChessGame():
	Engine(GameConfig::GAME_TITLE, GameConfig::WINDOW_DIM) {

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

void ChessGame::init() {
	changeScreen(*buildLandingPage());
}

void ChessGame::update() {

}

void ChessGame::handleLeftMouseClick(Point p) {
	Cell selectedCell = CellUtils::pointToCell(p, GameConfig::CELL_DIM, Point::ZERO);

	if (engine->isCellSelected()) {
		engine->movePiece(selectedCell);
	} else {
		engine->selectCell(selectedCell);
	}
}

void ChessGame::handleBtnClick([[maybe_unused]]int32_t idx) {
}

Widget* ChessGame::buildLandingPage() {
	// Make button manager per widget instance
	Widget* landingPageWidget = new Widget(Point::ZERO);

	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, GameConfig::WINDOW_DIM);
	landingPageWidget->put(*background);

	RectTextButton* btn = getFactory().createButton(
		GameConfig::NEW_GAME_BTN_POS,
		GameConfig::DEFAULT_BTN_DIM,
		GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
		GameConfig::DEFAULT_BTN_TEXT_COLOR,
		GameConfig::NEW_GAME_BTN_TEXT,
		defaultFont,
		std::bind(&ChessGame::handleStartGameButton, this)
	);
	landingPageWidget->put(*btn);

	return landingPageWidget;
}

Widget* ChessGame::buildChessPage() {
	initialiseChessClasses();
	Widget* chessPageWidget = new Widget(Point::ZERO);

	Object* background = getFactory().createObject(Resources::startScreen2, Point::ZERO, GameConfig::WINDOW_DIM);
	chessPageWidget->put(*background);

	Object* board = getFactory().createObject(Resources::board, Point::ZERO, GameConfig::BOARD_DIM);
	chessPageWidget->put(*board);

	RectTextButton* btn = getFactory().createButton(
		GameConfig::QUIT_GAME_BTN_POS,
		GameConfig::QUIT_GAME_BTN_DIM,
		GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
		GameConfig::DEFAULT_BTN_TEXT_COLOR,
		GameConfig::QUIT_GAME_BTN_TEXT,
		defaultFont,
		std::bind(&ChessGame::handleQuitGameButton, this)
	);
	chessPageWidget->put(*btn);

	chessPageWidget->onDestroy(std::bind(&ChessGame::onChessWidgetDestroy, this));

	return chessPageWidget;
}

void ChessGame::handleStartGameButton() {
	changeScreen(*buildChessPage());
	createPieceObjects();
	board->subscribe(std::bind(&ChessGame::pieceMovedCallback, this, std::placeholders::_1, std::placeholders::_2));
}

void ChessGame::handleQuitGameButton() {
	changeScreen(*buildLandingPage());
}

void ChessGame::onChessWidgetDestroy() {
	delete board;
	delete baseMoveGen;
	delete moveGen;
	delete moveManager;
	delete engine;
}

void ChessGame::createPieceObjects() {
	const CellToPieceLookup& positions = board->getPiecePositions();

	for (auto const& [cell, piece] : positions) {
		Object& obj = *getFactory().createObject(
			pieceToResource[piece],
			CellUtils::cellToPoint(cell, GameConfig::CELL_DIM),
			GameConfig::CELL_DIM
		);

		int32_t id = rootScreen->put(obj);
		cellToObjectId[cell] = id;
		cellObject[cell] = &obj;
	}
}

void ChessGame::pieceMovedCallback(const Cell& source, const Cell& destination) {
	// Handle captured pieces
	if (!board->isEmptyCell(destination)) {
		rootScreen->remove(cellToObjectId[destination]);
		cellObject.erase(destination);
		cellToObjectId.erase(destination);
	}

	// Update data structures after move and captures
	Object* obj = cellObject[source];
	obj->move(CellUtils::cellToPoint(destination, GameConfig::CELL_DIM));
	cellObject.erase(source);

	int32_t id = cellToObjectId[source];
	cellToObjectId.erase(source);

	cellObject[destination] = obj;
	cellToObjectId[destination] = id;
}

void ChessGame::initialiseChessClasses() {
	board = new ChessBoard();
	baseMoveGen = new BoardBoundsPieceMoveGenerator(*board);
	moveGen = new FriendlyFireExcludedMoveGenerator(*board, *baseMoveGen);
	moveManager = new ChessMoveManager(*board, *moveGen);
	engine = new ChessEngine(*board, *moveManager);
}

void ChessGame::handleComputerMove() {

}

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

#include "examples/chess/chess-engine/FriendlyFireExcludedMoveGenerator.h"
#include "examples/chess/chess-engine/ChessEngine.h"
#include "examples/chess/chess-engine/BoardBoundsPieceMoveGenerator.h"
#include "examples/chess/chess-engine/ChessMoveManager.h"
#include "examples/chess/chess-engine/ChessMoveLog.h"
#include "examples/chess/chess-engine/MoveLogWidget.h"
#include "engine/components/textstack/TextStack.h"
#include "engine/repositories/TextRepository.h"
#include "platform/filesys/FileSystem.h"

#include "platform/thread/ThreadUtils.h"

/**
 * Tip of the day: Stack-based allocation is eager. Heap based allocation is lazy.
 */
ChessGame::ChessGame() :
		Engine(GameConfig::GAME_TITLE, GameConfig::WINDOW_DIM), whitePlayerType(
				PlayerType::HUMAN), blackPlayerType(PlayerType::HUMAN) {

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
	if (engine != nullptr && engine->getState() == ChessState::COMPUTER_MOVE) {
		engine->makeComputerMove();
		ThreadUtils::sleepFor(50000); // When CPUs play 1v1 you can't see the moves.
	}
}

void ChessGame::handleLeftMouseClick(Point p) {
	Cell selectedCell = CellUtils::pointToCell(p, GameConfig::CELL_DIM,
			Point::ZERO);

	if (engine == nullptr) {
		return;
	}

	if (engine->isCellSelected()) {
		clearPossibleMoves();
		engine->movePiece(selectedCell);
	} else {
		if (engine->selectCell(selectedCell)) {
			fillPossibleMoves(selectedCell);
		}
	}
}

void ChessGame::fillPossibleMoves(const Cell &target) {
	possibleMoveCellsIds.clear();
	CellUnorderedSet possibleMoves = moveGen->generatePieceMoves(target);

	for (const Cell &c : possibleMoves) {
		Rect *r = getFactory().createRect(
				CellUtils::cellToPoint(c, GameConfig::CELL_DIM, Point::ZERO),
				GameConfig::CELL_DIM, GameConfig::HIGHLIGHT_COLOR);

		int32_t id = rootScreen->put(*r);

		possibleMoveCellsIds.push_back(id);
	}
}

void ChessGame::clearPossibleMoves() {
	for (int32_t id : possibleMoveCellsIds) {
		rootScreen->remove(id);
	}

	possibleMoveCellsIds.clear();
}

void ChessGame::handleBtnClick([[maybe_unused]]int32_t idx) {
}

Widget* ChessGame::buildLandingPage() {
	// Make button manager per widget instance
	Widget *landingPageWidget = new Widget(Point::ZERO);

	Object *background = getFactory().createObject(Resources::startScreen2,
			Point::ZERO, GameConfig::WINDOW_DIM);
	landingPageWidget->put(*background);

	Text *title = getFactory().createText(GameConfig::TITLE_TEXT, defaultFont,
			GameConfig::TITLE_POS, GameConfig::TITLE_DIM, Color::BLUE);
	landingPageWidget->put(*(Object*) title);

	RectTextButton *btn = getFactory().createButton(GameConfig::NEW_GAME_BTN_POS,
			GameConfig::DEFAULT_BTN_DIM, GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::NEW_GAME_BTN_TEXT,
			defaultFont, std::bind(&ChessGame::handleStartGameButton, this));
	landingPageWidget->put(*btn);

	RectTextButton *humanVsComputerBtn = getFactory().createButton(
			GameConfig::HUMAN_VS_COMPUTER_POS, GameConfig::DEFAULT_BTN_DIM,
			GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::HUMAN_VS_COMPUTER_TEXT,
			defaultFont, std::bind(&ChessGame::handleHumanVSComputerButton, this));
	landingPageWidget->put(*humanVsComputerBtn);

	RectTextButton *computerVsComputerBtn = getFactory().createButton(
			GameConfig::COMPUTER_VS_COMPUTER_POS, GameConfig::DEFAULT_BTN_DIM,
			GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::COMPUTER_VS_COMPUTER_TEXT,
			defaultFont, std::bind(&ChessGame::handleComputerVSComputerButton, this));
	landingPageWidget->put(*computerVsComputerBtn);

	RectTextButton *continueGameBtn = getFactory().createButton(
			GameConfig::CONTINUE_GAME_BTN_POS, GameConfig::DEFAULT_BTN_DIM,
			GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::CONTINUE_GAME_BTN_TEXT,
			defaultFont, std::bind(&ChessGame::handleContinueGameButton, this));
	landingPageWidget->put(*continueGameBtn);

	return landingPageWidget;
}

Widget* ChessGame::buildChessPage() {
	initialiseChessClasses();
	Widget *chessPageWidget = new Widget(Point::ZERO);

	Object *background = getFactory().createObject(Resources::startScreen2,
			Point::ZERO, GameConfig::WINDOW_DIM);
	chessPageWidget->put(*background);

	Object *boardObj = getFactory().createObject(Resources::board, Point::ZERO,
			GameConfig::BOARD_DIM);
	chessPageWidget->put(*boardObj);

	RectTextButton *btn = getFactory().createButton(GameConfig::QUIT_GAME_BTN_POS,
			GameConfig::QUIT_GAME_BTN_DIM, GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::QUIT_GAME_BTN_TEXT,
			defaultFont, std::bind(&ChessGame::handleQuitGameButton, this));
	chessPageWidget->put(*btn);

	RectTextButton *saveGameBtn = getFactory().createButton(GameConfig::SAVE_GAME_BTN_POS,
			GameConfig::SAVE_GAME_BTN_DIM, GameConfig::DEFAULT_BTN_BACKGROUND_COLOR,
			GameConfig::DEFAULT_BTN_TEXT_COLOR, GameConfig::SAVE_GAME_BTN_TEXT,
			defaultFont, std::bind(&ChessGame::handleSaveGameButton, this));
	chessPageWidget->put(*saveGameBtn);

	chessPageWidget->onDestroy(std::bind(&ChessGame::onChessWidgetDestroy, this));

	logTextWidget = new MoveLogWidget(GameConfig::LOG_TEXT_POS, getFactory(),
			defaultFont, GameConfig::LOG_LINE_CAP);

	chessPageWidget->addChild(*logTextWidget);

	std::cout << board->serialize() << std::endl;

	return chessPageWidget;
}

void ChessGame::startChessGame() {
	changeScreen(*buildChessPage());

	// TODO: Load pieces from file or go with the default order.

	createPieceObjects();
	board->subscribe(
			std::bind(&ChessGame::pieceMovedCallback, this, std::placeholders::_1,
					std::placeholders::_2));
	log->subscribe(
			std::bind(&ChessGame::handleMoveLog, this, std::placeholders::_1));
}

void ChessGame::handleStartGameButton() {
	whitePlayerType = PlayerType::HUMAN;
	blackPlayerType = PlayerType::HUMAN;
	startChessGame();
}

void ChessGame::handleQuitGameButton() {
	changeScreen(*buildLandingPage());
}

void ChessGame::handleHumanVSComputerButton() {
	whitePlayerType = PlayerType::HUMAN;
	blackPlayerType = PlayerType::COMPUTER;
	startChessGame();
}

void ChessGame::handleComputerVSComputerButton() {
	whitePlayerType = PlayerType::COMPUTER;
	blackPlayerType = PlayerType::COMPUTER;
	startChessGame();
}

void ChessGame::handleSaveGameButton() {
	FileSystem::overwriteFile(GameConfig::SAVE_GAME_PATH, board->serialize());
}

void ChessGame::handleContinueGameButton() {

}

void ChessGame::handleMoveLog(const Move &move) {
	std::stringstream ss;
	ss << move;
	logTextWidget->add(ss.str(), GameConfig::LOG_LINE_WIDTH);
	putLogText();
}

void ChessGame::onChessWidgetDestroy() {
	delete board;
	delete baseMoveGen;
	delete moveGen;
	delete moveManager;
	delete engine;
	delete log;
}

void ChessGame::createPieceObjects() {
	const CellToPieceLookup &positions = board->getPiecePositions();

	for (auto const& [cell, piece] : positions) {
		Object &obj = *getFactory().createObject(pieceToResource[piece],
				CellUtils::cellToPoint(cell, GameConfig::CELL_DIM),
				GameConfig::CELL_DIM);

		int32_t id = rootScreen->put(obj);
		cellToObjectId[cell] = id;
		cellObject[cell] = &obj;
	}
}

void ChessGame::pieceMovedCallback(const Cell &source,
		const Cell &destination) {
	// Handle captured pieces
	if (!board->isEmptyCell(destination)) {
		rootScreen->remove(cellToObjectId[destination]);
		cellObject.erase(destination);
		cellToObjectId.erase(destination);
	}

	// Update data structures after move and captures
	Object *obj = cellObject[source];
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
	log = new ChessMoveLog();
	engine = new ChessEngine(*board, *moveManager, *log, whitePlayerType,
			blackPlayerType);
}

void ChessGame::handleComputerMove() {

}

void ChessGame::putLogText() {

}

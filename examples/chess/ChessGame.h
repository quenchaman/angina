#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include <utility>
#include <vector>
#include <unordered_set>

#include "examples/chess/chess-engine/ChessEngine.h"
#include "engine/Engine.h"
#include "renderer/primitives/Dimensions.h"
#include "examples/chess/chess-engine/PieceToObjectTranslator.h"

struct Widget;
struct Object;
struct Piece;
struct Cell;

typedef std::unordered_set<Cell, Object&, Cell::HashFunction> CellToObjectLookup;

class ChessGame : public Engine {
public:
	ChessGame();
	~ChessGame();

	void init();
	void update();
	void handleLeftMouseClick(Point p);
	void handleBtnClick(int32_t idx);
private:
	ChessEngine engine;
	PieceToObjectTranslator pieceToResourceTranslator;
	CellToObjectLookup cellObject;
	ChessState state = ChessState::WHITE_PLAYER;

	void setState(ChessState newState);

	Widget* buildLandingPage();
	Widget* buildChessPage();

	void handleStartGameButton();

	/*
	 * For every piece in the chess engine, create a drawable object. Keep a mapping between the two.
	 */
	void createPieceObjects();

	void pieceMovedCallback(const Cell& source, const Cell& destination);

	void handleComputerMove();
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */

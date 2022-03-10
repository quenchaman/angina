#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include <utility>
#include <vector>
#include <unordered_map>
#include <string>

#include "examples/chess/chess-engine/ChessEngine.h"
#include "examples/chess/chess-engine/Piece.h"
#include "examples/chess/chess-engine/Cell.h"

#include "engine/Engine.h"
#include "renderer/primitives/Dimensions.h"

struct Widget;
struct Object;

typedef std::unordered_map<Cell, Object*, Cell::HashFunction> CellToObjectLookup;
typedef std::unordered_map<Piece, std::string, Piece::HashFunction> PieceToResourcePath;

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
	CellToObjectLookup cellObject;
	ChessState state = ChessState::WHITE_PLAYER;
	PieceToResourcePath pieceToResource;

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

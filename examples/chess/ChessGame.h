#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include <vector>

#include "examples/chess/chess-engine/ChessEngine.h"
#include "engine/Engine.h"
#include "renderer/primitives/Dimensions.h"
#include "examples/chess/chess-engine/PieceToObjectTranslator.h"

struct Widget;

struct PieceCellObjectTriple {
	PieceCellObjectTriple(Piece& p, Cell& c, Object& o): piece(p), cell(c), object(o) {}

	Piece& piece;
	Cell& cell;
	Object& object;
};

class ChessGame : public Engine {
public:
	ChessGame();
	~ChessGame();

	void print();
	void init();
	void update();
	void handleLeftMouseClick(Point p);
	void handleBtnClick(int32_t idx);
private:
	ChessEngine engine;
	PieceToResourcePath pieceToResource;
	std::vector<PieceCellObjectTriple> pieceCellObjectTriples;
	const Dimensions cellDim = { 80, 80 }; // TODO: Move this to chess config

	Widget* buildLandingPage();
	Widget* buildChessPage();

	void handleStartGameButton();

	/*
	 * Methods to handle piece to object translation/conversion.
	 */
	void initPieceToObjectConversion();
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */

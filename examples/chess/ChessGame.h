#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include <utility>
#include <vector>

#include "examples/chess/chess-engine/ChessEngine.h"
#include "engine/Engine.h"
#include "renderer/primitives/Dimensions.h"
#include "examples/chess/chess-engine/PieceToObjectTranslator.h"

struct Widget;
struct Object;
struct Piece;
struct Cell;

struct CellObjectPair {
	Cell cell;
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
	PieceToObjectTranslator pieceToResourceTranslator;
	std::vector<CellObjectPair> cellObjectPairs;

	Widget* buildLandingPage();
	Widget* buildChessPage();

	void handleStartGameButton();

	/*
	 * Methods to handle piece to object translation/conversion.
	 */
	void initPieceToObjectConversion();

	void pieceMovedCallback(const Cell& source, const Cell& destination);
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */

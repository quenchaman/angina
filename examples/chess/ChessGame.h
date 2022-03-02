#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include "examples/chess/chess-engine/ChessEngine.h"
#include "engine/Engine.h"

struct Widget;

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

	Widget* buildLandingPage();
	Widget* buildChessPage();

	void handleStartGameButton();
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */

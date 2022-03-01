#ifndef EXAMPLES_CHESS_CHESSGAME_H_
#define EXAMPLES_CHESS_CHESSGAME_H_

#include "examples/chess/chess-engine/ChessEngine.h"
#include "engine/Engine.h"



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
};

#endif /* EXAMPLES_CHESS_CHESSGAME_H_ */

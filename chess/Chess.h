/*
 * Chess.h
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_CHESS_H_
#define CHESS_CHESS_H_

#include "sdl/graphics/Engine.h"
#include "resources/Resources.h"

#include <vector>
#include <string>

class Chess : public Engine {
public:
	void init();
	void executeGameLogic();
	void draw();

	void handleUpArrowKey() {};
	void handleDownArrowKey() {};
	void handleLeftArrowKey() {};
	void handleRightArrowKey() {};
	void handleOtherKey() {};
private:
	Image* board;
	std::vector<std::string> paths = {
		Resources::board,
		Resources::blackBishop,
		Resources::blackKing,
		Resources::blackKnight,
		Resources::blackPawn,
		Resources::blackQueen,
		Resources::blackRook,
		Resources::whiteBishop,
		Resources::whiteKing,
		Resources::whiteKnight,
		Resources::whitePawn,
		Resources::whiteQueen,
		Resources::whiteRook
	};
};


#endif /* CHESS_CHESS_H_ */

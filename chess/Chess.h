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
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "State.h"
#include "sdl/graphics/Image.h"
#include "sdl/graphics/Texture.h"
#include "Cell.h"
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <random>

class Chess : public Engine {
public:
    Chess();
	void init();
	void executeGameLogic();
	void draw();

	void handleUpArrowKey() {};
	void handleDownArrowKey() {};
	void handleLeftArrowKey() {};
	void handleRightArrowKey() {};
	void handleOtherKey() {};
	void handleLeftMouseClick();
private:
    Image* board;
    std::vector<Piece*> activePieces;
    std::vector<Piece*> passivePieces;
    Side currentSide;
    State currentState;
    bool inCheck;
    Side winner;
    bool isDraw;
    bool isWhiteHuman;
    bool isBlackHuman;

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
		Resources::whiteRook,
        Resources::startScreen,
        Resources::whiteWins,
        Resources::blackWins
	};
private:
    void setPiecesOnBoard();
};


#endif /* CHESS_CHESS_H_ */

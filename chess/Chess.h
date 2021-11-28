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
	Image* boardImage;
    Image* startScreen;
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
	std::vector<Piece*> pieces;
	std::map<int32_t, Image*> pieceImages;
	Piece* selectedPiece;
	State state = State::INIT;
	std::default_random_engine randomEngine = {};
	Side turn = Side::White;
	bool inCheck = false;
    Image* winnerBanner;

	Piece* findPieceAtCell(Cell cell);
	bool move(Piece* piece, Cell cell);
	bool isAllowedMove(std::vector<Cell> moves, Cell targetMove, Piece* piece);
	bool makeComputerMove();
    void newGameSetup();
};


#endif /* CHESS_CHESS_H_ */

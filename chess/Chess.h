/*
 * Chess.h
 *
 *  Created on: Nov 15, 2021
 *      Author: ubuntu
 */

#ifndef CHESS_CHESS_H_
#define CHESS_CHESS_H_

#include "sdl/graphics/Engine.h"
#include "sdl/primitives/Rect.h"
#include "resources/Resources.h"
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "State.h"
#include "Move.h"
#include "Constants.h"
#include "sdl/graphics/Image.h"
#include "sdl/graphics/Texture.h"
#include "Cell.h"
#include <cstdint>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <sdl/components/Button.h>

class Chess : public Engine {
public:
    Chess();
	void init();
	void executeGameLogic();
	void draw();
    void deinit();

	void handleUpArrowKey() {};
	void handleDownArrowKey() {};
	void handleLeftArrowKey() {};
	void handleRightArrowKey() {};
	void handleOtherKey() {};
	void handleLeftMouseClick();
private:
    Image* board;
    Image* startScreen;
    Button* newGameBtn;
    Button* continueGameBtn;
    Button* quitGameButton;
    Button* quitGameButtonOnStartPage;
    std::vector<Piece*> activePieces;
    std::vector<Piece*> passivePieces;
    std::vector<Cell> availableMoves;
    Side currentSide;
    State currentState;
    bool inCheck;
    Side winner;
    Cell selectedCell = {0, 0, true};
    Cell targetCell = {0, 0, true};
    Piece* selectedPiece;
    std::map<Cell, Piece*> piecesMap;
    std::default_random_engine rng = std::default_random_engine {};
    Image* clock;
    std::chrono::time_point<std::chrono::steady_clock> clockStartTime;
    int32_t turnDuration = Constants::turnDuration;
    Move lastMove;
    int32_t currentRotation = 0;
    Image* winnerText;
    std::vector<Move> movesLog;
    std::vector<Image*> logImages;
    Button* saveGameBtn;
private:
    void setPiecesOnBoard();
    Piece* getPieceOnCell(Cell cell);
    bool isOwnPiece(Piece* piece);
    void populatePiecesMap();
    void filterOutsideOfBoardMoves();
    void filterOutPawnAttackMoves();
    void filterOutExposeKingMoves();
    void filterOutOccupiedCellsMoves();
    bool putPiece();
    void clearSelection();
    void switchPlayer();
    void makeComputerMove();
    void calculateCaptures();
    void createClock();
    bool performCastling(Piece* king, Piece* rook);
    void showLastTenMoves();
    void saveGame();
    void loadGame();
    double scoreMove(Cell move);
};


#endif /* CHESS_CHESS_H_ */

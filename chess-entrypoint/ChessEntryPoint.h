//
// Created by ubuntu on 11/28/21.
//

#ifndef ANGINA_TEST_H
#define ANGINA_TEST_H


#include "sdl/engine/Engine.h"
#include "chess-game/states/ChessState.h"
#include "sdl/primitives/Point.h"
#include "chess-game/board/Cell.h"
#include "chess-game/board/PieceSelectionManager.h"

struct ChessPage;
struct Piece;

class ChessEntryPoint : public Engine {
public:
	ChessEntryPoint();
    ~ChessEntryPoint() override;

    void init() override;

    void update() override;

    void handleLeftMouseClick(Point point) override;

    void handleBtnClick(int32_t idx) override;

    void transitionState(ChessState newState);

    void clearSelection();

private:
    Page* initWelcomePage();
    Page* initChessPage();
    ChessState state = ChessState::NO_OP;
    Point clickedPoint = Point::UNDEFINED;
    Cell clickedBoardCell = Cell::UNDEFINED;
    Piece* selectedPiece = nullptr;
    ChessPage* chessPage = nullptr;
    PieceSelectionManager* pieceSelectionMng;

    void handleHumanSelectPieceState();
    void handlePieceSelectedState();
};


#endif //ANGINA_TEST_H

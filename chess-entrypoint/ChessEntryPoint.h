#ifndef ANGINA_TEST_H
#define ANGINA_TEST_H


#include "engine/Engine.h"
#include "chess-game/states/ChessState.h"
#include "renderer/primitives/Point.h"
#include "chess-game/board/Cell.h"

struct ChessPage;
struct Piece;
struct PieceSelectionManager;
struct ValidMovesGenerator;
struct AI;

class ChessEntryPoint : public Engine {
public:
	ChessEntryPoint();
    ~ChessEntryPoint() override;

    void init() override;

    void update() override;

    void handleLeftMouseClick(Point point) override;

    void handleBtnClick(int32_t idx) override;

    void transitionState(ChessState newState);

    void unclick();

private:
    Page* initWelcomePage();
    Page* initChessPage();
    ChessState state = ChessState::NO_OP;
    Point clickedPoint = Point::UNDEFINED;
    ChessPage* chessPage = nullptr;
    PieceSelectionManager* pieceSelectionMng;
    ValidMovesGenerator* validMovesGenerator;
    AI* ai;

    void handleHumanSelectPieceState();
    void handlePieceSelectedState();
    void handleFinishHumanMove();
    void handleComputerMove();
};


#endif //ANGINA_TEST_H

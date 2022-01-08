//
// Created by ubuntu on 11/28/21.
//

#ifndef ANGINA_TEST_H
#define ANGINA_TEST_H


#include "sdl/engine/Engine.h"

class ChessEntryPoint : public Engine {
public:
	ChessEntryPoint();
    ~ChessEntryPoint() override;

    void init() override;

    void update() override;

    void handleLeftMouseClick() override;

    void handleBtnClick(int32_t idx) override;

private:

    Page* initWelcomePage();
    Page* initChessPage();
};


#endif //ANGINA_TEST_H

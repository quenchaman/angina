//
// Created by ubuntu on 11/28/21.
//

#ifndef ANGINA_TEST_H
#define ANGINA_TEST_H


#include "sdl/engine/Engine.h"

class Test : public Engine {
public:
    Test();
    ~Test() override;

    void init() override;

    void update() override;

    void handleLeftMouseClick() override;

    void handleBtnClick(int32_t idx) override;
};


#endif //ANGINA_TEST_H

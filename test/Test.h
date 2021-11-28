//
// Created by ubuntu on 11/28/21.
//

#ifndef ANGINA_TEST_H
#define ANGINA_TEST_H


#include <sdl/graphics/Engine.h>
#include <resources/Resources.h>

class Test : public Engine {
public:
    Test();
    ~Test() override;

    void init() override;

    void draw() override;

    void executeGameLogic() override;

    void handleUpArrowKey() override;

    void handleDownArrowKey() override;

    void handleLeftArrowKey() override;

    void handleRightArrowKey() override;

    void handleOtherKey() override;

    void handleLeftMouseClick() override;

private:
    std::vector<std::string> assets = { Resources::board };
    Image* board;
};


#endif //ANGINA_TEST_H

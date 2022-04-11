#ifndef EXAMPLES_TEST_TEST_H_
#define EXAMPLES_TEST_TEST_H_

#include "engine/Engine.h"

struct Sprite;

class Test : public Engine {
public:
    Test();
    virtual ~Test() = default;

    void init();
    void update();
    void handleLeftMouseClick(Point);
    void handleBtnClick(int32_t idx);
private:
    Sprite* sprite;
};

#endif /* EXAMPLES_TEST_TEST_H_ */

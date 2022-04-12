#ifndef EXAMPLES_TOWERDEFENCE_TOWERDEFENCE_H_
#define EXAMPLES_TOWERDEFENCE_TOWERDEFENCE_H_

#include "engine/Engine.h"

struct Sprite;

class TowerDefence : public Engine {
public:
	TowerDefence();
    virtual ~TowerDefence() = default;

    void init();
    void update();
    void handleLeftMouseClick(Point);
    void handleBtnClick(int32_t idx);
private:
    Sprite* sprite;
};

#endif /* EXAMPLES_TOWERDEFENCE_TOWERDEFENCE_H_ */

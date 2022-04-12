#include <iostream>
#include <vector>

#include "examples/towerdefence/HeroController.h"
#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Line.h"
#include "renderer/shapes/Rect.h"

#include "engine/sprites/Sprite.h"
#include "TowerDefence.h"

TowerDefence::TowerDefence(): Engine("Test", Dimensions {400, 400}), sprite(nullptr) {}

void TowerDefence::init() {
    Object& hero = getFactory().createObject(Resources::circleSprite, Point{0, 0}, Dimensions{100,100});

    addComponent(hero);
    addBehaviour(*new HeroController(hero));

    addComponent(*new Line(Point{100, 100}, Point{100, 200}, Color::RED));

    hero.setVelocity(100).setDestination(Point{100, 200});
    addMovement(hero);

}

void TowerDefence::update() {
	//sprite->next();
}

void TowerDefence::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void TowerDefence::handleBtnClick([[maybe_unused]]int32_t idx) {

}

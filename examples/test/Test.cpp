#include "Test.h"

#include <iostream>
#include <vector>

#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Line.h"
#include "renderer/shapes/Rect.h"
#include "examples/test/HeroController.h"

#include "engine/sprites/Sprite.h"

Test::Test(): Engine("Test", Dimensions {400, 400}), sprite(nullptr) {}

void Test::init() {
    Object& hero = getFactory().createObject(Resources::circleSprite, Point{0, 0}, Dimensions{100,100});
    std::vector<Rect> spriteStates = {
    		Rect{0,0,100,100},
				Rect{100,0,100,100},
				Rect{0,100, 100, 100},
				Rect{100, 100, 100, 100}
    };

    sprite = new Sprite(hero, spriteStates);

    addComponent(hero);
    addBehaviour(*new HeroController(hero));

    addComponent(*new Line(Point{100, 100}, Point{100, 200}, Color::RED));
}

void Test::update() {
	sprite->next();
}

void Test::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

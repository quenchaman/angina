#include "Test.h"

#include <iostream>

#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Object.h"

Test::Test(): Engine("Test", Dimensions {400, 400}) {}

void Test::init() {
    Object& hero = getFactory().createObject(Resources::blackKing, Point{0, 0}, Dimensions{80,80});

    addComponent(hero);
}

void Test::update() {

}

void Test::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

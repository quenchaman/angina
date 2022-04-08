#include "Test.h"

#include <iostream>

#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Object.h"

Test::Test(): Engine("Test", Dimensions {400, 400}) {}

void Test::init() {
    Object& image = getFactory().createObject(Resources::blackKing, Point{80, 80}, Dimensions{80,80});
    Object& image2 = getFactory().createObject(Resources::blackKing, Point{160, 160}, Dimensions{80,80});
    Object& image3 = getFactory().createObject(Resources::blackKing, Point{240, 240}, Dimensions{80,80});
    Object& image4 = getFactory().createObject(Resources::blackKing, Point{320, 320}, Dimensions{80,80});

    addComponent(image);
    addComponent(image2);
    addComponent(image3);
    addComponent(image4);
}

void Test::update() {

}

void Test::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

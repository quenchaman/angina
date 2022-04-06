#include "Test.h"

#include <iostream>



#include "resources/Resources.h"

// TODO: Move Point and Dimensions to the 'core' package.
#include "renderer/primitives/Point.h"
#include "renderer/primitives/Dimensions.h"
#include "renderer/primitives/Object.h"

Test::Test(): Engine("Test", Dimensions {400, 400}) {}

void Test::init() {
    Screen* HelloWorldScreen = new Screen();
    std::cout << "First entry point should be here?" << std::endl;
    Object& image = getFactory().createObject(Resources::blackKing, Point::ZERO, Dimensions{80,80});
    std::cout << "Are we reaching here?" << std::endl;
    HelloWorldScreen->put(*dynamic_cast<Drawable*>(&image));
    std::cout << "What about here?" << std::endl;
}

void Test::update() {

}

void Test::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

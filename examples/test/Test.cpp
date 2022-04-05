#include "Test.h"

#include <iostream>

Test::Test(): Engine("Test", Dimensions {400, 400}) {}

void Test::init() {
    std::cout << "Hello world!" << std::endl;
}

void Test::update() {

}

void Test::handleLeftMouseClick([[maybe_unused]] Point p) {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {

}

#include "TestEngine.h"

#include <iostream>

#include "resources/Resources.h"

TestEngine::TestEngine(): Engine("Hello SDL!", Dimensions {640, 480}) {}

void TestEngine::init() {
	Object& obj = getFactory().createObject(Resources::TD::background, Point::ZERO, Dimensions {640, 480});
	addComponent(obj);
}

void TestEngine::update() {
}

void TestEngine::handleLeftMouseClick(Point p) {
	std::cout << p << std::endl;
}

void TestEngine::handleBtnClick([[maybe_unused]]int32_t idx) {

}

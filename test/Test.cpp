//
// Created by ubuntu on 11/28/21.
//

#include "Test.h"

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <string>

#include "sdl/primitives/Rect.h"
#include "sdl/engine/object/Object.h"
#include "resources/Resources.h"
#include "sdl/components/Button.h"
#include "sdl/engine/page/Page.h"
#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

Test::~Test() {

}

void Test::init() {
	navigateTo(initWelcomePage());
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

void Test::handleBtnClick([[maybe_unused]]int32_t idx) {
	std::cout << "Clicked button is " << idx << std::endl;
}

Page* Test::initWelcomePage() {
	Page* welcomePage = createNewPage();

	welcomePage->addButton(0, Resources::gas, Point{0, 0});
	welcomePage->addButton(1, Resources::brake, Point{150, 0});

	welcomePage->addObject(0, Resources::wheel, Point{0, 100});

	return welcomePage;
}

// TODO: We must have a way to specify how big the window should be
Test::Test() : Engine("Test", { 800, 800 }) {

}

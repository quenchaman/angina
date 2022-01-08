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
#include "chess-game/pages/LandingPage.h"

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
	LandingPage* landing = new LandingPage(*getRenderer());

	return landing;
}

// TODO: We must have a way to specify how big the window should be
Test::Test() : Engine("Test", { 800, 800 }) {

}

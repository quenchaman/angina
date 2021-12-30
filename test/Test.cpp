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

Test::~Test() {

}

void Test::init() {
	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[0] = Resources::blackBishop;

	loadButtons(idToPaths);

	buttonManager.getButton(0).move(0, 0);
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

void Test::handleBtnClick(int32_t idx) {
	std::cout << "Button was clicked with index" << idx << std::endl;
}

Test::Test() : Engine("Test") {

}

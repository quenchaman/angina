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
	idToPaths[1] = Resources::whiteBishop;
	std::unordered_map<int32_t, int32_t> idToPageIdx;
	idToPageIdx[0] = 0;
	idToPageIdx[1] = 1;

	loadButtons(idToPaths, idToPageIdx);

	buttonManager.getButton(0).move(0, 0);
	buttonManager.getButton(1).move(0, 0);
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

void Test::handleBtnClick(int32_t idx) {
	std::cout << "The clicked index is " << idx << std::endl;
	if (idx == 0) {
		navigateTo(1);
	} else if (idx == 1) {
		navigateTo(0);
	}
}

Test::Test() : Engine("Test") {

}

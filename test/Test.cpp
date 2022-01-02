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

Test::~Test() {

}

void Test::init() {
	navigateTo(initWelcomePage());
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

void Test::handleBtnClick(int32_t idx) {
	std::cout << "The clicked index is " << idx << std::endl;
	if (idx == 0) {
		navigateTo(initSecondPage());
	} else if (idx == 1) {
		navigateTo(initWelcomePage());
	}
}

Page* Test::initWelcomePage() {
	Page* welcomePage = createNewPage();

	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[0] = Resources::blackBishop;

	welcomePage->loadButtons(idToPaths);
	welcomePage->buttonManager.getButton(0).move(0, 0);

	return welcomePage;
}

Page* Test::initSecondPage() {
	Page* welcomePage = createNewPage();

	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[1] = Resources::whiteBishop;

	welcomePage->loadButtons(idToPaths);
	welcomePage->buttonManager.getButton(1).move(0, 0);

	return welcomePage;
}

Test::Test() : Engine("Test") {

}

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

Test::~Test() {

}

void Test::init() {
	std::unordered_map<int32_t, std::string> idToTexts;
	idToTexts[10] = "Zdraveite!";

	loadText(idToTexts);
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

Test::Test() : Engine("Test") {

}

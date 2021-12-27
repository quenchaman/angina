//
// Created by ubuntu on 11/28/21.
//

#include "Test.h"

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <string>

#include "sdl/primitives/Rect.h"

Test::~Test() {

}

void Test::init() {
	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[0] = "../resources/chess/black_wins.png";
    loadResources(idToPaths);

    Rect* rectangle = new Rect(0, 0, 150, 150, Color::GREEN);

    addRectangle(8, *rectangle);
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

Test::Test() : Engine("Test") {

}

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
	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[0] = Resources::blackKing;
    loadResources(idToPaths);

    Rect* rectangle = new Rect(40, 40, 150, 150, Color::GREEN);
    Texture* king = resources[0];
    Object* obj = new Object(*king, *rectangle);
    objects[0] = obj;
}

void Test::update() {
}

void Test::handleLeftMouseClick() {

}

Test::Test() : Engine("Test") {

}

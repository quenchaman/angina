//
// Created by ubuntu on 11/28/21.
//

#include "Test.h"

#include <iostream>
#include <unordered_map>
#include <cstdint>
#include <string>

Test::~Test() {

}

void Test::init() {
	std::unordered_map<int32_t, std::string> idToPaths;
	idToPaths[0] = "../resources/chess/black_wins.png";
    loadResources(idToPaths);

    std::cout << "Test game initialized" << std::endl;
}

void Test::update() {
	std::cout << "Updating game state" << std::endl;
}

void Test::handleLeftMouseClick() {

}

Test::Test() : Engine("Test") {

}

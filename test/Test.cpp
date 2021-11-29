//
// Created by ubuntu on 11/28/21.
//

#include "Test.h"

Test::~Test() {

}

void Test::init() {
    loadGameResources(assets);

    this->board = resources[Resources::board];
    this->board->spin();
}

void Test::draw() {
    this->board->draw(*renderer);
}

void Test::executeGameLogic() {

}

void Test::handleUpArrowKey() {

}

void Test::handleDownArrowKey() {

}

void Test::handleLeftArrowKey() {

}

void Test::handleRightArrowKey() {

}

void Test::handleOtherKey() {

}

void Test::handleLeftMouseClick() {

}

Test::Test() : Engine("Test") {

}

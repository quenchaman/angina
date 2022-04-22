#include "TestEngine.h"

#include <iostream>

#include "resources/Resources.h"

TestEngine::TestEngine(): GameEngine(), txt(nullptr) {
    GameEngine::init("Hello SDL!", 640, 480);
}

void TestEngine::onStart() {
    int32_t idx = textureComponent.loadTexture(Resources::Engine::arrow);
    txt = &textureComponent.getTexture(idx);
}

void TestEngine::handleEvent() {
    if (inputComponent.touchEvent == TouchEvent::KEYBOARD_PRESS) {
        if (inputComponent.key == Keyboard::KEY_UP) {
            txt->rotateClockwise(3.1416);
        } else if (inputComponent.key == Keyboard::KEY_DOWN) {
            txt->rotateCounterClockwise(3.1416);
        } else if (inputComponent.key == Keyboard::KEY_LEFT) {
            txt->activateHFlip();
            txt->rotateCounterClockwise(3.1416);
        }
    }
}

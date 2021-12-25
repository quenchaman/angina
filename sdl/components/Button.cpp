//
// Created by ubuntu on 12/4/21.
//

#include "Button.h"

#include <utility>

#include "SDL.h"

#include "sdl/primitives/Point.h"

Button::Button(int32_t x, int32_t y, const Texture& texture): x(x), y(y), texture(texture) {

}


int32_t Button::getX() {
    return this->x;
}

int32_t Button::getY() {
    return this->y;
}

bool Button::isClicked(const Point& p) {
    return true;
}

Button::~Button() {
    delete texture;
}

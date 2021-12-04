//
// Created by ubuntu on 12/4/21.
//

#include "Button.h"

#include <utility>

Button::Button(int32_t x, int32_t y, Image *image): x(x), y(y), image(image) {
    this->image->put(x, y);
    this->rect = new Rect(x, y, this->image->getBoundingBox().w, this->image->getBoundingBox().h);
}

void Button::draw(Renderer& renderer) {
    this->image->draw(renderer);
}

int32_t Button::getX() {
    return this->x;
}

int32_t Button::getY() {
    return this->y;
}

bool Button::isClicked(SDL_Point p) {
    return this->rect->isInRect(p);
}

Button::~Button() {
    delete image;
}

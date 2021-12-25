/*
 * Rect.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Rect.h"

#include "SDL_shape.h"

Rect::Rect(int32_t x, int32_t y, int32_t w, int32_t h) {
	this->_rect = { x, y, w, h };
}

SDL_Rect Rect::getRaw() {
	return this->_rect;
}

bool Rect::isInRect(SDL_Point point) {
    return point.x >= _rect.x && point.x <= (_rect.x + _rect.w) && point.y >= _rect.y && point.y <= _rect.y + _rect.h;
}

Rect::Rect(SDL_Rect rect): _rect(rect) {
}

void Rect::draw([[maybe_unused]]Renderer &renderer) {

}

void Rect::draw([[maybe_unused]]Renderer &renderer, [[maybe_unused]]const SDL_Rect *destRect) {

}

void Rect::draw([[maybe_unused]]Renderer &renderer, [[maybe_unused]]const SDL_Rect *destRect, [[maybe_unused]]double angle) {

}

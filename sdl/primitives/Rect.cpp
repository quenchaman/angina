/*
 * Rect.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Rect.h"

Rect::Rect(int32_t x, int32_t y, int32_t w, int32_t h) {
	this->_rect = { x, y, w, h };
}

SDL_Rect Rect::getRaw() {
	return this->_rect;
}

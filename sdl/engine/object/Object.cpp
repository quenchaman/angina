/*
 * Object.cpp
 *
 *  Created on: Dec 27, 2021
 *      Author: ubuntu
 */

#include <iostream>

#include "Object.h"

#include "sdl/primitives/Rect.h"
#include "sdl/graphics/Texture.h"

Object::Object(Texture& t, Rect& rect): texture(t), rectangle(rect) {}

Object::~Object() {
	delete &texture;
	delete &rectangle;

	std::cout << "Object destroyed" << std::endl;
}

void Object::move(int32_t x, int32_t y) {
	rectangle.rect.x = x;
	rectangle.rect.y = y;
}

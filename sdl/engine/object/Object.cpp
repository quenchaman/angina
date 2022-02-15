#include <iostream>

#include "Object.h"

#include "sdl/primitives/Rect.h"
#include "sdl/graphics/Texture.h"
#include "sdl/graphics/Renderer.h"

Object::Object(Texture& t, Rect& rect): texture(t), rectangle(rect) {}

void Object::move(const int32_t x, const int32_t y) {
	rectangle.rect.x = x;
	rectangle.rect.y = y;
}

Point Object::getPosition() const {
	return {rectangle.rect.x, rectangle.rect.y};
}

Object::~Object() {
	delete& texture;

	std::cout << "Object destroyed" << std::endl;
}

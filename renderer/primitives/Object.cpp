#include <iostream>

#include "Object.h"

#include "renderer/shapes/Rect.h"
#include "platform/sdl/primitives/Texture.h"
#include "renderer/primitives/Color.h"
#include "renderer/Renderer.h"
#include "renderer/utils/PrimitivesUtils.h"

Object::Object(Texture &t, Dimensions d, Point p) :
		texture(t), dim(d), point(p), center(
				PrimitivesUtils::calculateCenter(p, dim)), clip(Rect::UNDEFINED) {
}

void Object::move(const int32_t x, const int32_t y) {
	point.x = x;
	point.y = y;

	center = PrimitivesUtils::calculateCenter(point, dim);
}

void Object::move(const Point &p) {
	move(p.x, p.y);
}

Point Object::getPosition() const {
	return point;
}

Dimensions Object::getDimensions() const {
	return dim;
}

Point Object::getCenter() const {
	return center;
}

Texture& Object::getTexture() {
	return texture;
}

Transformation Object::getTransformation() const {
	return transformation;
}

void Object::setClip(Rect clipRect) {
	clip = clipRect;
}

Rect Object::getClip() const {
	return clip;
}

Object::~Object() {
	std::cout << "Object destroyed" << std::endl;
}

void Object::draw(Renderer &renderer) {
	//std::cout << "I am being drawn at " << rectangle.rect.x << " and " << rectangle.rect.y << std::endl;
	renderer.render(*this);
}

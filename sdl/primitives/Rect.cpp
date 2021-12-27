/*
 * Rect.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Rect.h"

const Rect Rect::ZERO(0, 0, 0, 0, Color::NONE);
const Rect Rect::UNDEFINED(10000, 10000, 0, 0, Color::NONE);

Rect::Rect(const Point& positionIn, const Dimensions& dimensionsIn, const Color& colorIn) {
	pos = positionIn;
	dimensions = dimensionsIn;
	color = colorIn;
	rect = { positionIn.x, positionIn.y, dimensions.w, dimensions.h };
}

Rect::Rect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color): Rect::Rect({x, y}, {w, h}, color) {}

bool Rect::operator==(const Rect& other) const {
	return pos.x == other.pos.x && pos.y == other.pos.y && dimensions.w == other.dimensions.w && dimensions.h == other.dimensions.h;
}

bool Rect::operator!=(const Rect& other) const {
	return !(*this == other);
}

bool Rect::isInRect(const Point& point) {
    return point.x >= pos.x && point.x <= (pos.x + dimensions.w) &&
    		point.y >= pos.y && point.y <= pos.y + dimensions.h;
}

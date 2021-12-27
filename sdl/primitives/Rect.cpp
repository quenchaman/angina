/*
 * Rect.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "Rect.h"

#include "sdl/primitives/Point.h"

Rect::Rect(const Point& positionIn, const Dimensions& dimensionsIn) {
	pos = positionIn;
	dimensions = dimensionsIn;
	rect = { positionIn.x, positionIn.y, dimensions.w, dimensions.h };
}

Rect::Rect(int32_t x, int32_t y, int32_t w, int32_t h): Rect::Rect({x, y}, {w, h}) {}

bool Rect::isInRect(const Point& point) {
    return point.x >= pos.x && point.x <= (pos.x + dimensions.w) &&
    		point.y >= pos.y && point.y <= pos.y + dimensions.h;
}

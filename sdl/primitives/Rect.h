/*
 * Rectangle.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_RECT_H_
#define SDL_PRIMITIVES_RECT_H_

#include <iostream>

#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"
#include "sdl/primitives/Color.h"

#include "SDL_shape.h"

class Rect {
public:
	Rect(Point positionIn, Dimensions dimensionsIn, Color colorIn);
	Rect(int32_t x, int32_t y, int32_t w, int32_t h, const Color& color);

	SDL_Rect rect;
	Color color;

	bool operator==(const Rect& other) const;
	bool operator!=(const Rect& other) const;

	bool isInRect(const Point& point);

	static const Rect ZERO;
	static const Rect UNDEFINED;

	friend std::ostream& operator<<(std::ostream& os, const Rect& rect);
};

#endif /* SDL_PRIMITIVES_RECT_H_ */

/*
 * Rectangle.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_RECT_H_
#define SDL_PRIMITIVES_RECT_H_

#include "sdl/primitives/Point.h"
#include "sdl/primitives/Dimensions.h"

#include "SDL_shape.h"

class Rect {
public:
	Rect(const Point& position, const Dimensions& dim);

	Point pos;
	Dimensions dimensions;
	SDL_Rect rect;

	bool isInRect(const Point& point);
};


#endif /* SDL_PRIMITIVES_RECT_H_ */

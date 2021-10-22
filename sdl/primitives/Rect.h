/*
 * Rectangle.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_RECT_H_
#define SDL_PRIMITIVES_RECT_H_

#include <cstdint>

#include "SDL.h"

class Rect {
public:
	Rect(int32_t x, int32_t y, int32_t w, int32_t h);

	SDL_Rect getRaw();
private:
	SDL_Rect _rect;
};


#endif /* SDL_PRIMITIVES_RECT_H_ */

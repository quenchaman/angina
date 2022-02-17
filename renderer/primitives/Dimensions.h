/*
 * Dimension.h
 *
 *  Created on: Dec 25, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_DIMENSIONS_H_
#define SDL_PRIMITIVES_DIMENSIONS_H_

#include <cstdint>

struct Dimensions {
	Dimensions() = default;
	Dimensions(int32_t w, int32_t h);

	int32_t w = 0;
	int32_t h = 0;

	static const Dimensions UNDEFINED;
};


#endif /* SDL_PRIMITIVES_DIMENSIONS_H_ */

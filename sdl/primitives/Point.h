/*
 * Point.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_POINT_H_
#define SDL_PRIMITIVES_POINT_H_

#include <cstdint>

class Point {
public:
	Point(int32_t x, int32_t y);

	int32_t getX();
	int32_t getY();
private:
	int32_t x;
	int32_t y;
};


#endif /* SDL_PRIMITIVES_POINT_H_ */

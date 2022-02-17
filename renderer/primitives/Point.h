/*
 * Point.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_PRIMITIVES_POINT_H_
#define SDL_PRIMITIVES_POINT_H_

#include <cstdint>

struct Point {
	Point() = default;
	Point(int32_t x, int32_t y);

	int32_t x = 0;
	int32_t y = 0;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;

	static const Point ZERO;
	static const Point UNDEFINED;
};

#endif /* SDL_PRIMITIVES_POINT_H_ */

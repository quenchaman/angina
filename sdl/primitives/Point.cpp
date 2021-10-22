/*
 * Point.cpp
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#include "SDL.h"

#include "Point.h"

Point::Point(int32_t _x, int32_t _y): x(_x), y(_y) {}

int32_t Point::getX() {
	return this->x;
}

int32_t Point::getY() {
	return this->y;
}

#ifndef SDL_PRIMITIVES_POINT_H_
#define SDL_PRIMITIVES_POINT_H_

#include <cstdint>

struct Point {
	Point();
	Point(int32_t x, int32_t y);

	int32_t x;
	int32_t y;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
	Point operator+(const Point& other) const;
	Point operator-(const Point& other) const;

	static const Point ZERO;
	static const Point UNDEFINED;
};

#endif /* SDL_PRIMITIVES_POINT_H_ */

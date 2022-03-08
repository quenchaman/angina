#ifndef SDL_PRIMITIVES_POINT_H_
#define SDL_PRIMITIVES_POINT_H_

#include <cstdint>
#include <iostream>

struct Point {
	Point();
	Point(int32_t x, int32_t y);

	int32_t x;
	int32_t y;

	bool operator==(const Point&) const;
	bool operator!=(const Point&) const;
	Point operator+(const Point&) const;
	Point operator-(const Point&) const;

	static const Point ZERO;
	static const Point UNDEFINED;

	friend std::ostream& operator<<(std::ostream&, const Point&);
};

#endif /* SDL_PRIMITIVES_POINT_H_ */

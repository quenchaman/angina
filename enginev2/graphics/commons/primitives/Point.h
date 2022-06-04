#ifndef SDL_PRIMITIVES_POINT_H_
#define SDL_PRIMITIVES_POINT_H_

#include <iostream>
#include <cstdint>

/**
 * I am also using this struct as a 2D vector...Hopefully that does not backfire...
 */
struct Point {
	Point();
	Point(int32_t x, int32_t y);

	int32_t x;
	int32_t y;

	bool operator==(const Point&) const;
	bool operator!=(const Point&) const;
	bool operator>(const Point&) const;
	Point operator+(const Point&) const;
	Point operator-(const Point&) const;

	static const Point ZERO;
	static const Point UNDEFINED;

	struct Hash {
	  size_t operator()(const Point& p) const {
	    return p.x + p.y * 10;
	  }
	};

	friend std::ostream& operator<<(std::ostream&, const Point&);
};

Point operator*(int32_t scalar, const Point& p);

Point operator*(const Point& p, int32_t scalar);

Point operator/(const Point& p, int32_t scalar);

#endif /* SDL_PRIMITIVES_POINT_H_ */

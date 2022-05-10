#include "Line.h"

Line::Line(const Point& start, const Point& end, const Color& clr): a(start), b(end), color(clr) {}

Line Line::operator+(const Line& other) const {
	return Line(a, b + other.b, Color::BLACK);
}

Line Line::operator*(int32_t scalar) {
	return Line(a, b * scalar, color);
}

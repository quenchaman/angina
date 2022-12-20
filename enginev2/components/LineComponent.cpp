#include "LineComponent.h"

void LineComponent::emplace(const Point& start, const Point& end, const Color& clr) {
	data.emplace_back(start, end, clr);
}

#include "LineComponent.h"

const int32_t MAX_LINES = 2048;

LineComponent::LineComponent() {
	lines.reserve(MAX_LINES);
}

void LineComponent::loadLine(const Point& start, const Point& end, const Color& clr) {
	lines.emplace_back(start, end, clr);
}

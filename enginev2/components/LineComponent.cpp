#include "LineComponent.h"

const int32_t MAX_LINES = 2048;

LineComponent::LineComponent(): PrimitivesComponent(2048) {}

void LineComponent::loadLine(const Point& start, const Point& end, const Color& clr) {
	data.emplace_back(start, end, clr);
}

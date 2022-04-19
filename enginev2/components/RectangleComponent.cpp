#include "RectangleComponent.h"

const int32_t MAX_RECTS = 1000000;

RectangleComponent::RectangleComponent() {
	rectangles.reserve(MAX_RECTS);
}

void RectangleComponent::loadRectangle(const Point& p, const Dimensions& dim, const Color& color, bool fill) {
	rectangles.emplace_back(p, dim, color, fill);
}

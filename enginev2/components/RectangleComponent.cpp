#include "RectangleComponent.h"

RectangleComponent::RectangleComponent() {}

void RectangleComponent::loadRectangle(const Point& p, const Dimensions& dim, const Color& color, bool fill) {
	data.emplace_back(p, dim, color, fill);
}

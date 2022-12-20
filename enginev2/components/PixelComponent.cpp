#include "PixelComponent.h"

PixelComponent::PixelComponent() {}

void PixelComponent::loadPixel(const Point& point, const Color& color) {
	data.emplace_back(point, color);
}

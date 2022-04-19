#include "PixelComponent.h"

const int32_t MAX_PIXELS = 8294400;

PixelComponent::PixelComponent() {
	pixels.reserve(MAX_PIXELS);
}

void PixelComponent::loadPixel(const Point& point, const Color& color) {
	pixels.emplace_back(point, color);
}

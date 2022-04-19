#include "PixelComponent.h"

PixelComponent::PixelComponent(): PrimitivesComponent(8294400) {}

void PixelComponent::loadPixel(const Point& point, const Color& color) {
	data.emplace_back(point, color);
}

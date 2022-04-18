#include "SurfaceComponent.h"

const int32_t MAX_IMAGES = 1000000;

SurfaceComponent::SurfaceComponent() {
	surfaces.reserve(MAX_IMAGES);
}

void SurfaceComponent::loadSurface(const std::string& pathToResource) {
	surfaces.emplace_back(pathToResource);
}

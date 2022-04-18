#include "SurfaceComponent.h"

#include "SDL.h"

#include "enginev2/graphics/sdl/window/Window.h"


const int32_t MAX_IMAGES = 1000000;

SurfaceComponent::SurfaceComponent() {
	surfaces.reserve(MAX_IMAGES);
}

void SurfaceComponent::loadSurface(const std::string& pathToResource) {
	surfaces.emplace_back(pathToResource);
}

void SurfaceComponent::loadSurfaceOptim(const std::string& pathToResource, Window& window) {
	Surface surface(pathToResource);

	SDL_Surface* optimSurface = SDL_ConvertSurface(surface.surface, window.surface->format, 0);

	surfaces.emplace_back(optimSurface);
}

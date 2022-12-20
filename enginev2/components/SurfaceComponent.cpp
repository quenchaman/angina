#include "SurfaceComponent.h"

#include "SDL.h"

#include "enginev2/graphics/sdl/window/Window.h"

SurfaceComponent::SurfaceComponent() {}

void SurfaceComponent::loadSurface(const std::string& pathToResource) {
	data.emplace_back(pathToResource);
}

void SurfaceComponent::loadSurfaceOptim(const std::string& pathToResource, Window& window) {
	Surface surface(pathToResource);

	SDL_Surface* optimSurface = SDL_ConvertSurface(surface.surface, window.surface->format, 0);

	data.emplace_back(optimSurface);
}

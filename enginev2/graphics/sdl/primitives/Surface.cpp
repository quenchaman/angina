#include "Surface.h"

#include <iostream>

#include "SDL_surface.h"
#include "SDL_image.h"

#include "exceptions/ResourceLoadException.h"

Surface::Surface(const std::string& surfaceAssetPath): surface(nullptr) {
	surface = IMG_Load(surfaceAssetPath.c_str());

	// TODO: Handle with default image
	if (surface == nullptr) {
		throw ResourceLoadException(SDL_GetError());
	}
}

Surface::Surface(SDL_Surface* rawSurface): surface(rawSurface) {}

Surface::~Surface() {
	SDL_FreeSurface(surface);

	std::cout << "Surface destroyed" << std::endl;
}

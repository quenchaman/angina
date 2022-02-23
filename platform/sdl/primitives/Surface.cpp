#include "Surface.h"

#include <iostream>

#include "SDL_surface.h"

Surface::Surface(SDL_Surface* surface) {
	this->surface = surface;
}

Surface::~Surface() {
	if (surface != nullptr) {
		SDL_FreeSurface(surface);
		surface = nullptr;
	}

	std::cout << "Surface destroyed" << std::endl;
}

SDL_Surface* Surface::getSurface() {
	return surface;
}

#include "Surface.h"

#include <iostream>

#include "SDL_surface.h"

Surface::Surface(SDL_Surface& s): surface(&s) {}

SDL_Surface& Surface::getSurface() {
	return *surface;
}

Surface::~Surface() {
	SDL_FreeSurface(surface);

	std::cout << "Surface destroyed" << std::endl;
}

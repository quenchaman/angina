/*
 * Surface.cpp
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#include "Surface.h"

#include "SDL_surface.h"

Surface::Surface(SDL_Surface* surface) {
	this->_surface = surface;
}

Surface::~Surface() {
	if (_surface != nullptr) {
		SDL_FreeSurface(_surface);
		_surface = nullptr;
	}
}

void Surface::paint(const Surface& other) {
	SDL_BlitSurface(other._surface, NULL, _surface, NULL);
}

SDL_PixelFormat* Surface::getFormat() {
	return _surface->format;
}

SDL_Surface* Surface::getSurface() {
	return _surface;
}

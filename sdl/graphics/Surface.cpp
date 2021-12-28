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

SDL_Surface* Surface::getSurface() {
	return _surface;
}

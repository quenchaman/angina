/*
 * Surface.cpp
 *
 *  Created on: Oct 13, 2021
 *      Author: ubuntu
 */

#include "Surface.h"

Surface::Surface(SDL_Surface* surface) {
	this->_surface = surface;
}

Surface::~Surface() {
	SDL_FreeSurface(this->_surface);
}

void Surface::paint(const Surface& other) {
	SDL_BlitSurface(other._surface, NULL, this->_surface, NULL);
}

SDL_PixelFormat* Surface::getFormat() {
	return this->_surface->format;
}

SDL_Surface* Surface::getSurface() {
	return this->_surface;
}

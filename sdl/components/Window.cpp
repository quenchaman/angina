/*
 * Window.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#include "SDL.h"

#include "Window.h"
#include "exceptions/WindowInitException.h"

Window::Window(std::string title, int x, int y, int w, int h, SDL_WindowFlags flags) {
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (window == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	SDL_Surface* ws = SDL_GetWindowSurface(this->window);

	if (ws == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	this->surface = new Surface(ws);
}

SDL_Window* Window::getWindow() {
	return this->window;
}

Surface& Window::getWindowSurface() {
	return *this->surface;
}

void Window::updateWindowSurface() {
	SDL_UpdateWindowSurface(this->window);
}

Window::~Window() {
	SDL_DestroyWindow(this->window);
}

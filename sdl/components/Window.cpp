/*
 * Window.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */
#include "Window.h"

#include "SDL_video.h"
#include "SDL_surface.h"

#include "exceptions/WindowInitException.h"

Window::Window(std::string title, Point pos, Dimensions dimensions, int32_t flags) {
	window = SDL_CreateWindow(title.c_str(), pos.x, pos.y, dimensions.w, dimensions.h, flags);

	if (window == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	SDL_Surface* ws = SDL_GetWindowSurface(window);

	if (ws == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	surface = new Surface(ws);
}

SDL_Window* Window::getWindow() {
	return window;
}

Surface& Window::getSurface() {
	return *surface;
}

void Window::update() {
	SDL_UpdateWindowSurface(window);
}

Window::~Window() {
	delete surface;

	if (window != nullptr) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}
}

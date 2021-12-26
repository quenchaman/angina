/*
 * Window.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */
#include "Window.h"

#include <iostream>

#include "SDL_video.h"
#include "SDL_surface.h"

#include "sdl/components/Surface.h"
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

	std::cout << "Window initialised" << std::endl;
}

SDL_Window* Window::getWindow() {
	return window;
}

Surface& Window::getSurface() {
	return *surface;
}

Window::~Window() {
	delete surface;

	if (window != nullptr) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	std::cout << "Window deinitialised" << std::endl;
}

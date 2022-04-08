#include "Window.h"

#include <iostream>

#include "SDL_video.h"
#include "SDL_surface.h"

#include "platform/sdl/primitives/Surface.h"
#include "exceptions/WindowInitException.h"

/**
 * Not great to have exceptions thrown in constructors.
 * But, if we cannot get window's surface then the game cannot start and we should not worry about memory leaks.
 * ...But this is still poor. TODO: Improve it.
 *
 */
Window::Window(std::string title, Point pos, Dimensions dimensions,
		int32_t flags) {
	window = SDL_CreateWindow(title.c_str(), pos.x, pos.y, dimensions.w,
			dimensions.h, flags);

	if (window == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	surface = SDL_GetWindowSurface(window);

	if (surface == nullptr) {
		throw WindowInitException(SDL_GetError());
	}

	std::cout << "Window initialised" << std::endl;
}

SDL_Window* Window::getWindow() {
	return window;
}

SDL_Surface* Window::getSurface() {
	return surface;
}

Window::~Window() {
	if (window != nullptr) {
		SDL_DestroyWindow(window);
		window = nullptr;
	}

	std::cout << "Window destroyed" << std::endl;
}

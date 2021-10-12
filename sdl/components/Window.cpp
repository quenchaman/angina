/*
 * Window.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#include "SDL.h"

#include "Window.h"

Window::Window(std::string title, int x, int y, int w, int h, SDL_WindowFlags flags) {
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (window == nullptr) {
		std::cerr << "SDL_CreateWindow() failed with reason - " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
}

/*
 * Graphics.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#include "Graphics.h"

namespace Graphics {
	const int32_t imgFlags = IMG_INIT_PNG;

	void boot() {
		if (SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS) {
			throw GraphicsInitException(SDL_GetError());
		}
	}

	void bootImageExtension() {
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			throw GraphicsInitException(SDL_GetError());
		}
	}

	Renderer& bootRenderer(SDL_Window* window) {
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (renderer == nullptr) {
			throw GraphicsInitException(SDL_GetError());
		}

		return *new Renderer(renderer);
	}
}

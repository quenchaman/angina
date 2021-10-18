/*
 * Graphics.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */
#include <cstdint>

#include "SDL.h"
#include "SDL_image.h"

#include "Graphics.h"
#include "exceptions/GraphicsInitException.h"

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
}

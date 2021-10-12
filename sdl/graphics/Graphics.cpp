/*
 * Graphics.cpp
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */
#include "SDL.h"

#include "Graphics.h"
#include "exceptions/GraphicsInitException.h"

namespace Graphics {
	void boot() {
		if (SDL_Init(SDL_INIT_VIDEO) != EXIT_SUCCESS) {
			throw GraphicsInitException(SDL_GetError());
		}
	}
}

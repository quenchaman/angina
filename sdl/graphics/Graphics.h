/*
 * Graphics.h
 *
 *  Created on: Oct 12, 2021
 *      Author: valeri
 */

#ifndef SDL_GRAPHICS_GRAPHICS_H_
#define SDL_GRAPHICS_GRAPHICS_H_

#include <cstdlib>
#include <cstdint>

#include "SDL.h"
#include "SDL_image.h"

#include <SDL.h>

#include "exceptions/GraphicsInitException.h"

namespace Graphics {
	void boot();
	void bootImageExtension();
	SDL_Renderer* bootRenderer(SDL_Window* window);
}


#endif /* SDL_GRAPHICS_GRAPHICS_H_ */

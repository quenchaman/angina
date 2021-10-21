/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include "sdl/components/Surface.h"
#include "exceptions/GraphicsInitException.h"
#include "SDL.h"

class Texture {
public:
	Texture(SDL_Texture* texture);

	SDL_Texture* getTexture();
private:
	SDL_Texture* texture;
};


#endif /* SDL_GRAPHICS_TEXTURE_H_ */

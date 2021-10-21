/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include "sdl/components/Surface.h"
#include "sdl/graphics/Renderer.h"
#include "exceptions/GraphicsInitException.h"

class Texture {
public:
	Texture(Surface& surface, Renderer& renderer);

	SDL_Texture* getTexture();
private:
	SDL_Texture* texture;

	SDL_Texture* fromSurface(Surface& surface, Renderer& renderer);
};


#endif /* SDL_GRAPHICS_TEXTURE_H_ */

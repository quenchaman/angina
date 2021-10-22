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
#include "sdl/graphics/Drawable.h"
#include "SDL.h"

#include "sdl/graphics/Renderer.h"

class Texture : public Drawable {
public:
	Texture();
	Texture(SDL_Texture* texture);

	SDL_Texture* getTexture();
	void draw(Renderer& renderer);
private:
	SDL_Texture* texture;
};


#endif /* SDL_GRAPHICS_TEXTURE_H_ */

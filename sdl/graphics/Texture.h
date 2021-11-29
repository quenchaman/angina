/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include <iostream>

#include "sdl/components/Surface.h"
#include "exceptions/GraphicsInitException.h"
#include "sdl/graphics/Drawable.h"
#include "SDL.h"
#include "sdl/graphics/Renderer.h"

class Texture : public Drawable {
public:
	Texture();
	~Texture();
	Texture(SDL_Texture* texture);

	SDL_Texture* getTexture();
    SDL_Point getSize();
	virtual void draw(Renderer& renderer) override;
	virtual void draw(Renderer& renderer, const SDL_Rect* destRect) override;
    virtual void draw(Renderer& renderer, SDL_Rect destRect, double angle, SDL_RendererFlip flip);
private:
	SDL_Texture* texture;
};


#endif /* SDL_GRAPHICS_TEXTURE_H_ */

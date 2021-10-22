/*
 * Renderer.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_RENDERER_H_
#define SDL_GRAPHICS_RENDERER_H_

#include "SDL.h"

#include "sdl/graphics/Drawable.h"

class Renderer {
public:
	Renderer(SDL_Renderer* renderer);

	void clearRenderer();
	SDL_Renderer* getRenderer();
	void render(Drawable& drawable);
	void updateScreen();
private:
	SDL_Renderer* renderer;
};


#endif /* SDL_GRAPHICS_RENDERER_H_ */

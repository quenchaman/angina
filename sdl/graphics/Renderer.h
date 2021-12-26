/*
 * Renderer.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_RENDERER_H_
#define SDL_GRAPHICS_RENDERER_H_

#include "sdl/graphics/Texture.h"
#include "sdl/primitives/Rect.h"
#include "sdl/components/Window.h"

struct SDL_Renderer;

class Renderer {
public:
	Renderer(Window& window);
	~Renderer();

	SDL_Renderer* getRenderer();
	void clear();
	void render(const Texture& texture);
	void render(const Rect& rect);
	void update();
private:
	void init(Window& window);
	void deinit();

	SDL_Renderer* renderer;
};


#endif /* SDL_GRAPHICS_RENDERER_H_ */

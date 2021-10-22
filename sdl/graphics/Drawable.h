/*
 * Renderable.h
 *
 *  Created on: Oct 22, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_RENDERERS_DRAWABLE_H_
#define SDL_GRAPHICS_RENDERERS_DRAWABLE_H_

struct Renderer;

class Drawable {
public:
	virtual ~Drawable() = 0;

	virtual void draw(Renderer& renderer) = 0;
};


#endif /* SDL_GRAPHICS_RENDERERS_DRAWABLE_H_ */

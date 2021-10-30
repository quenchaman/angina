/*
 * Image.h
 *
 *  Created on: Oct 30, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_IMAGE_H_
#define SDL_GRAPHICS_IMAGE_H_

#include "sdl/graphics/Texture.h"
#include "sdl/graphics/Renderer.h"
#include <SDL.h>
#include "sdl/primitives/Point.h"
#include "config/Globals.h"

class Image {
public:
	Image(Texture& texture, SDL_Rect _boundingBox);
	void draw(Renderer& renderer);
	void moveUp(int32_t y);
	void moveDown(int32_t y);
//	void moveLeft(int32_t x);
//	void moveRight(int32_t x);
private:
	Point& position;
	Texture& texture;
	SDL_Rect boundingBox;
};


#endif /* SDL_GRAPHICS_IMAGE_H_ */

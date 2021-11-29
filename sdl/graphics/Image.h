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
    ~Image();
	void draw(Renderer& renderer, double angle = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void spin();
	void moveUp(int32_t y);
	void moveDown(int32_t y);
	void moveLeft(int32_t x);
	void moveRight(int32_t x);

	void setX(int32_t x);
	void setY(int32_t y);
    void put(int32_t x, int32_t y);
    Texture* getTexture();
    SDL_Rect getBoundingBox();
private:
	Texture& texture;
	SDL_Rect boundingBox;
	int32_t maxSpinDegrees = 0.0;
	double spinIncrement = 4;
	double currentAngle = 0.0;
};


#endif /* SDL_GRAPHICS_IMAGE_H_ */

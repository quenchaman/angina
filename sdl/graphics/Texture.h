/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include "sdl/primitives/Dimensions.h"

struct SDL_Texture;
struct SDL_Point;
struct SDL_Texture;

class Texture {
public:
	Texture(SDL_Texture* texture);
	~Texture();

	SDL_Texture* getTexture() const;
	Dimensions getDimensions() const;
private:
	SDL_Texture* texture;
	Dimensions dimensions;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include <iostream>

struct SDL_Texture;
struct SDL_Point;

class Texture {
public:
	Texture(SDL_Texture* texture);
	~Texture();

	SDL_Texture* getTexture() const;

	friend std::ostream& operator<<(std::ostream& os, const Texture& t);
private:
	SDL_Texture* texture;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

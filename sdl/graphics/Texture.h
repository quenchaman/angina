/*
 * Texture.h
 *
 *  Created on: Oct 21, 2021
 *      Author: ubuntu
 */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include <iostream>
#include <cstdint>

struct SDL_Texture;
struct SDL_Point;

class Texture {
public:
	Texture(SDL_Texture* texture, int32_t w, int32_t h);
	~Texture();

	SDL_Texture* getTexture() const;
	int32_t w;
	int32_t h;

	friend std::ostream& operator<<(std::ostream& os, const Texture& t);
private:
	SDL_Texture* texture;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

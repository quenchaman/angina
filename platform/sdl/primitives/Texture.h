#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include <iostream>
#include <cstdint>

#include "renderer/primitives/Dimensions.h"

struct SDL_Texture;
struct SDL_Point;

class Texture {
public:
	Texture(SDL_Texture*, Dimensions);
	~Texture();

	SDL_Texture* getTexture() const;
	Dimensions getDimensions() const;

	friend std::ostream& operator<<(std::ostream&, const Texture&);
private:
	SDL_Texture *texture;
	Dimensions dimensions;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include "enginev2/graphics/commons/primitives/Dimensions.h"

struct SDL_Texture;
struct TextureRendererComponent;

/**
 * Wrapper around SDL_Texture and manages the life-cycle of it.
 */
class Texture {
public:
	friend class TextureRendererComponent;

	Texture(SDL_Texture*);
	~Texture();
private:
	SDL_Texture* texture;
	Dimensions dim;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

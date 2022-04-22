#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

#include "enginev2/graphics/commons/primitives/Dimensions.h"
#include "enginev2/graphics/sdl/primitives/Rectangle.h"

struct SDL_Texture;
struct TextureRendererComponent;

/**
 * Wrapper around SDL_Texture and manages the life-cycle of it.
 */
class Texture {
public:
	friend class TextureRendererComponent;

	Texture(SDL_Texture*);
	Texture(SDL_Texture*, Rectangle);
	~Texture();

	void setClip(const Rectangle&);
	void modulateColor(const Color&) const;
	void activateBlend() const;
	void setAlpha(uint8_t value) const;
private:
	SDL_Texture* texture;
	Dimensions dim;
	Rectangle clip;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

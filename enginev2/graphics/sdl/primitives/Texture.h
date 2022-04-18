#ifndef SDL_GRAPHICS_TEXTURE_H_
#define SDL_GRAPHICS_TEXTURE_H_

struct SDL_Texture;
struct TextureRendererComponent;

class Texture {
public:
	friend class TextureRendererComponent;

	Texture(SDL_Texture*);
	~Texture();
private:
	SDL_Texture *texture;
};

#endif /* SDL_GRAPHICS_TEXTURE_H_ */

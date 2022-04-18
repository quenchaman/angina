#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_

struct SDL_Renderer;
struct Window;
struct Texture;
struct TextureComponent;

class TextureRendererComponent {
public:
	friend class TextureComponent;

	void init(Window&);

	void clear();
	void render(Texture&);
	void update();
private:
	SDL_Renderer* sdlRenderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_ */

#ifndef ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_
#define ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_

struct SDL_Renderer;
struct Window;
struct Texture;
struct TextureComponent;
struct Rectangle;

class TextureRendererComponent {
public:
	friend class TextureComponent;

	~TextureRendererComponent();

	void init(Window&);

	void clear();
	void render(Texture&);
	void render(Rectangle&);
	void update();
private:
	SDL_Renderer* sdlRenderer;
};

#endif /* ENGINEV2_GRAPHICS_SDL_RENDERER_TEXTURERENDERERCOMPONENT_H_ */
